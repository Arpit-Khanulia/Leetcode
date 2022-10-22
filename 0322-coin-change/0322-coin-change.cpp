class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int a =  find(coins.size(),amount,coins,dp) ;
        if(a == INT_MAX-1) return -1;
        return a;
        
    }
    
    int find(int n, int sum, vector<int>&coins,vector<vector<int>>&dp){
        
        
        if(n==0)
        {
            
            if(sum == 0) return 0;
            if(sum <0) return INT_MAX-1;
            return INT_MAX-1;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(coins[n-1]<= sum){
            
            int l = 1+find(n,sum-coins[n-1],coins,dp) ;
            int r = find(n-1,sum,coins,dp);
            
            return dp[n][sum] =  min(l,r);
        }
        
        return dp[n][sum] = find(n-1,sum,coins,dp);
            
        
    }
};