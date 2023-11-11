class Solution {
public:
    
    int solve(int n, int k , int target,long long &sum,vector<vector<int>>&dp){
        
        
        if(n == 0){
            
            if(sum == target) return 1;
            return 0;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        long long count =0;
        
        for(int i=1; i<=k;i++){
            
            sum = sum+ i; 
            count += solve(n-1,k,target,sum,dp) % 1000000007 ;
            sum = sum-i;
            
        }
        
        return dp[n][sum] = count % 1000000007 ;
        
        
    }
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>>dp(n+1,vector<int>(k*n+1,-1));
        long long sum = 0;
        long long ans = 0;
        return solve(n,k,target,sum,dp);
    }
};