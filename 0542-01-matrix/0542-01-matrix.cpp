class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vi(m,vector<int>(n));
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0 ;i<m;i++){
            for(int j =0; j<n;j++){
                
                if(mat[i][j] == 0){
                    vi[i][j] =1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int drow[]= {1,0,-1,0};
        int dcol[]= {0,-1,0,1};
        
        while(!q.empty()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            vi[r][c]=1;
            
            int d = q.front().second;
            q.pop();
            mat[r][c] = d;
            
            for(int i=0; i<4;i++){
                
                int row = r+drow[i];
                int col = c+dcol[i];
                
                if(row<m && row>=0 && col<n&& col >=0 && !vi[row][col]){
                    vi[row][col] =1;
                    q.push({{row,col},d+1});
                }
                
                
            }
        }
        
        return mat;
        
    }
};