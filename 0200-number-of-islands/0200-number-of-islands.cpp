class Solution {
public:
    
    void dfs(int i, int j , vector<vector<int>>&vi,vector<vector<char>>&grid){
        
        vi[i][j] =1;
        int n = grid.size();
        int m = grid[0].size();
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        for(int k=0 ; k<4; k++){
            int row = i + drow[k];
            int col = j + dcol[k];
            
            if(row>=0 && row<n && col>=0 && col<m && !vi[row][col] && grid[row][col] == '1')
                dfs(row,col,vi,grid);
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int sizen = grid.size();
        int sizem = grid[0].size();
        
        vector<vector<int>>vi(sizen,vector<int>(sizem,0));
        int count=0;
        
        for(int i=0 ; i<sizen; i++){
            
            for(int j=0 ; j<sizem; j++){
                
                if(!vi[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(i,j,vi,grid);
                }
            }
        }
        
        return count;
    }
};