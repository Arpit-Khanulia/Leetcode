class Solution {
public:
    
    void dfs(int node,int parent,vector<pair<int,int>>adj[],int & count){
        
        for(auto i : adj[node])
        {
            if(i.first != parent){
                count += i.second;
                dfs(i.first,node,adj,count);
            }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<pair<int,int>>adj[n];
        for(auto i:connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        
        int count =0;
        dfs(0,-1,adj,count);
        
        return count;
        
    }
};