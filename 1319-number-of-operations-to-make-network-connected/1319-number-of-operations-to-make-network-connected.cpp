class Solution {
public:
    
    void dfs(int node, vector<int>&vi,vector<int>adj[]){
        vi[node] =1;
        
        for(int i: adj[node]){
            
            if(!vi[i]) dfs(i,vi,adj);
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int k  = connections.size();
        if(k < n-1) return -1;
        
        vector<int>vi(n);
        vector<int>adj[n];
        
        for(auto i : connections){
            
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int count=0;
        
        for(int i=0; i<n;i++){
            
            if(!vi[i]){
                dfs(i,vi,adj);
                count++;
                
            }
            
        }
        
        return count -1;
        
    }
};