class Solution {
public:
    
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vi,int r, int c){
        
        vi[r][c] =1;
        
        int n = board.size();
        int m = board[0].size();
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        for(int i=0;i<4;i++)
        {
            int row = r + drow[i];
            int col = c + dcol[i];
            
            if(row<n && row>=0 && col<m&& col>=0 && !vi[row][col] && board[row][col] == 'O')
                dfs(board,vi,row,col);
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vi(n,vector<int>(m));
        
        
        for(int i=0; i<m;i++)
        {
            if(board[0][i] == 'O') dfs(board,vi,0,i);
            if(board[n-1][i] == 'O') dfs(board,vi,n-1,i);
        }
        
        for(int i=0; i<n;i++){
            
            if(board[i][0] == 'O') dfs(board,vi,i,0);
            if(board[i][m-1] == 'O') dfs(board,vi,i,m-1);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m;j++){
                
                if(board[i][j] == 'O' && !vi[i][j])
                    board[i][j] = 'X';
            }
        }
            
    }
};