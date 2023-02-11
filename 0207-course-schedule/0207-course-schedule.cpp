class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int>adj[numCourses];
        
        for(int i=0; i<prerequisites.size();i++){
            
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        
        vector<int>indegree(numCourses);
        
        for(int i=0; i<numCourses; i++){
            
            for(auto j: adj[i])
                indegree[j]++;
        }
        
        
        queue<int>q;
        vector<int>topo;
        
        for(int i=0; i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
            
        }
            
        
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(int i: adj[node])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        if(topo.size() == numCourses) return 1;
        return 0;
        
        
    }
};