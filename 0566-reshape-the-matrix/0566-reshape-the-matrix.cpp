class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        
        int k =0; 
        int l =0;
        
        int row = mat.size();
        int col = mat[0].size();
        
        if(row * col != r*c) return mat;
        vector<vector<int>>ans(r,vector<int>(c));
        
        for(int i =0; i<row; i++){
            for(int j =0; j<col;j++){
               
                
                if(l<c){
                    
                    ans[k][l] = mat[i][j];
                    l++;
                    
                }
                else{
                    k++;
                    l =0;
                    ans[k][l] = mat[i][j];
                    l++;
                }
                    
            }
        }
        
        return ans;
    }
};