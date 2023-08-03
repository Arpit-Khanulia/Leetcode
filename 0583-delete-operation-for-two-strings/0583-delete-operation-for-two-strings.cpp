class Solution {
public:
    
    int find(string word1, string word2,int n ,int m, vector<vector<int>>&dp){
        
        if(n== 0 or m==0) return 0;  
        
        if(dp[n][m] != -1) return dp[n][m];
        if(word1[n-1] == word2[m-1])  return dp[n][m] =  1 + find(word1, word2, n-1,m-1,dp);
        else return dp[n][m] = max(find(word1,word2,n-1,m,dp),find(word1,word2,n,m-1,dp));
        
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int lcs = find(word1, word2, n,m, dp);
        
        int ans = n +m - 2*lcs;
        
        return ans; 
    }
};