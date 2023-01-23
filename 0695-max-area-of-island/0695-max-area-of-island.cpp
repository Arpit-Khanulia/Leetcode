class Solution {
public:
    
    int dfs(int r, int c, vector<vector<int>>&vi,vector<vector<int>>&grid,int count){
        
        int n = grid.size();
        int m = grid[0].size();
        vi[r][c] =1;
        
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        for(int i=0; i<4;i++){
            
            int row = r + drow[i];
            int col = c + dcol[i];
            
            if(row>=0 && row<n && col>=0 && col<m && !vi[row][col] && grid[row][col] ==1 )
                count = dfs(row,col,vi,grid,count) +1;
               
        }
        
        return count ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vi(n,vector<int>(m));
        int count =0;
        
        int maxi = 0;
        
        for(int i=0; i<n;i++){
            for(int j =0;j<m;j++){
                
                if(vi[i][j] == 0 && grid[i][j] == 1){
                    int count  = dfs(i,j,vi,grid,1);
                    maxi = max(maxi,count);
                }
            }
        }
        

        
        return maxi;
        
    }
};