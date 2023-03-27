class Solution {
public:
    long long find(vector<vector<int>>&grid,int i, int j,vector<vector<int>>&dp ){
        
        
        if(!(i<grid.size() and j<grid[0].size())) return INT_MAX;
        
        if(i == grid.size()-1 and j== grid[0].size()-1) return grid[i][j];
        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        long long int mina = grid[i][j] + find(grid,i+1,j,dp);
        long long int minb = grid[i][j] + find(grid,i,j+1,dp);
        

        return dp[i][j] = min(mina,minb);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return find(grid,0,0,dp);
        
    }
};