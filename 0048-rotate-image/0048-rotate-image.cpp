class Solution {
public:
    
    void print(vector<vector<int>>&matrix){
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0 ;i<n;i++){
            
            for(int j =0; j<m;j++){
                
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        cout<<endl<<endl;
        for(int i=0 ;i<n;i++){
            
            for(int j =i; j<m;j++){
                
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int i =0; 
        int j =m-1;
        
        while(i<j){
            
            for(int k=0; k<n;k++){
                
                swap(matrix[k][i],matrix[k][j]);
            }
            i++;
            j--;
        }
        
        
        
    }
};