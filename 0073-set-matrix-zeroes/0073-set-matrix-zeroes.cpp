class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>top(m);
        vector<int>left(n);
        
        
        for(int i=0; i<n;i++){
            for(int j =0; j<m;j++){
                
                if(matrix[i][j] == 0){
                    
                    top[j] =1;
                    left[i] =1;
                }
            }
        }
        
        for(int i=0; i<n;i++){
            
            for(int j=0; j<m;j++){
                
                if(top[j] || left[i] ) matrix[i][j] =0;
            }
        }
        
    }
};