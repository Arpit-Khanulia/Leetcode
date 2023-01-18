class Solution {
public:
    
    void dfs(int node, vector<int>&vi,vector<int>adj[]){
        
        vi[node] = 1;
        
        for(int i : adj[node]){
            
            if(!vi[i]) dfs(i,vi,adj);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();
        vector<int>vi(size);
        int count =0;
        
        vector<int>adj[size];
        
        for(int i=0; i<size; i++){
            for(int j =0; j<size;j++)
            {
                if(isConnected[i][j] ==1)
                adj[i].push_back(j);
                // adj[j].push_back(i);
                
            }
                
        }
        
        for(int i =0; i<size; i++){
            
            if(!vi[i]){
                count++;
                dfs(i,vi,adj);
            }
        }
        
        
        return count ;
    }
};