class Solution {
public:
    
    int solve(vector<vector<int>>&maze,int row,int col,vector<vector<int>>&dp){
        
        
        if(maze[row][col] == 1) return 0;
        int n = maze.size();
        int m = maze[0].size();
        
        
        if(dp[row][col] != -1) return dp[row][col];
        
        if(row == n-1 and col == m-1) return 1;
        
        int count =0;
        
        
        if(row+1< n) count += solve(maze,row+1,col,dp);
        
        if(col+1<m) count += solve(maze,row,col+1,dp);
        
        return dp[row][col] = count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        
        vector<vector<int>>dp(r+1,vector<int>(c+1,-1));
        return solve(obstacleGrid, 0,0,dp);
    }
};