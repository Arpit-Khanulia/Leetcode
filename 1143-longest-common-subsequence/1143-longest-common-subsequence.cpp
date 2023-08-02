class Solution {
public:
    
    int find(string &text1, string &text2, int m, int n,vector<vector<int>>&dp){
        
        if(m ==0 or n ==0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n]; 
        
        if(text1[m-1] == text2[n-1]) return dp[m][n] = 1 + find(text1,text2,m-1,n-1,dp);
        else return dp[m][n] = max(find(text1,text2,m-1,n,dp),find(text1,text2,m,n-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return find(text1,text2,text1.size(),text2.size(),dp);
    }
};