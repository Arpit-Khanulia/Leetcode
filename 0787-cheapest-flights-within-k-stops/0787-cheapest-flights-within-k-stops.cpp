class Solution {
public:
    
    int dfs(int src, int& dst, int k, vector<pair<int,int>>adj[],vector<vector<int>>&dp){

        
        
        int mini = 100000;
        
        if(src == dst) return 0;
        if(k < 0) return 100000;
        
        if(dp[src][k] != -1) return dp[src][k];
        
        for(auto i : adj[src])
        {
            int price = dfs(i.first,dst,k-1,adj,dp) + i.second;
            mini = min(price,mini);
            
        }
        
        return dp[src][k] = mini;
 
        
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];
        
        for(int i=0; i<flights.size();i++)
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        
        vector<vector<int>>dp (n+10,vector<int>(k+10,-1));
        
        int ans = dfs(src,dst,k,adj,dp);
        
        if(ans == 100000) return -1;
        return ans;
        
        
    }

};