class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
    
    bool solve (vector<vector<char>>&board){
        
        for(int i=0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){  
                if(board[i][j] == '.'){   
                    for(char k ='1';k<='9';k++){
                        if(isvalid(board,i,j,k)){
                            board[i][j]  = k;
                            
                            if(solve(board))
                                return true;
                            else
                            board[i][j] = '.'; 
                            
                        }
                    }
                    
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    
    
    
    
    bool isvalid(vector<vector<char>>&board, int i , int j , char k){
        
        for(int q = 0 ; q< 9 ;q++)
        {
            if(board[i][q] == k)
                return false;
            
            if(board[q][j] == k)
                return false;
            

//             if (board[3 * (i / 3) + q / 3][3 * (j / 3) + q % 3] == k)
//             return false;
            
             
        }
        
        int r = 3* (i/3);
        int c = 3* (j/3);
        
        for(int a =r ;a<r+3;a++)
            for(int b =c;b<c+3;b++)
                if(board[a][b] == k)
                    return false;
        
        return true;
    }
};