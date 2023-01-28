class Solution {
public:
    
    int find(vector<vector<int>>&triangle,int i, int j,vector<vector<int>>&dp){
        
        if(i== triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = find(triangle,i+1,j,dp);
        int b = find(triangle,i+1,j+1,dp);
        
        return dp[i][j] = triangle[i][j] + min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m+5,vector<int>(n+5,-1));
        return find(triangle,0,0,dp);
    }
};