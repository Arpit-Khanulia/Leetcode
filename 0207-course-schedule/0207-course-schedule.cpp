class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        
        for(int i=0; i<prerequisites.size();i++){
            
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>ans;
        vector<int>indgree(numCourses);
        queue<int>q;
        
        for(int i=0; i<numCourses;i++){
            
            for(int j: adj[i]){
                
                indgree[j]++;
            }
            
        }
        
        for(int i=0; i<indgree.size();i++){
            if(indgree[i] == 0) q.push(i);
        }
        
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(int i: adj[node]){
                
                indgree[i]--;
                if(indgree[i] == 0) q.push(i);
            }
            
        }
        
        if(ans.size() == numCourses) return 1;
        return 0;
    }
};