class Solution {
    int timer = 1;
public:
    
    
void dfs(int node,int parent, vector<int>adj[],vector<int>&vi,vector<int>& time, vector<int>& low,vector<vector<int>>&bridges){
        
        vi[node] =1;
        
        time[node] = low[node] =timer;
        timer ++;
        
        for(int i: adj[node]){
            
            if(i == parent) continue;
            if(!vi[i]){
                
                
                dfs(i,node,adj,vi,time,low,bridges);
                low[node] = min(low[node],low[i]);
                if(time[node] < low[i]) bridges.push_back({node,i});
                
            }
            else{
                
                low[node] =min(low[node],low[i]);
                
            }
            
            
            
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>time(n);
        vector<int>low(n);
        vector<vector<int>>bridges;
        
        
        vector<int>vi(n);
        
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        dfs(0,-1,adj,vi,time,low,bridges);
        
        return bridges;
        
        
            
        
    }
};