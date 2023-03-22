class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>>adj[n+1];
        vector<int>vi(n+1);
        
        for(auto i: roads){
            
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
            
        }
        
        queue<int>q;
        q.push(1);
        vi[1] =1;
        
        int ans = INT_MAX;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto i: adj[node]){
                
                if(!vi[i.first]){
                    vi[i.first] =1;
                    q.push(i.first);
                    
                }
                ans = min(ans,i.second);
                
            }
        }
        
        return ans;
        
    }
};