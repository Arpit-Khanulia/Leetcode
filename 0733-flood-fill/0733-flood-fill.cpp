class Solution {
public:
    
    void dfs(int i,int j, int color, vector<vector<int>>&image, vector<vector<int>>&vi,int c){
        
        int n = image.size();
        int m = image[0].size();
        vi[i][j] =1;
        image[i][j] = color;
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,-1,0,1};
        
        for(int k=0; k<4;k++){
            
            int row = i + drow[k];
            int col = j + dcol[k];
            
            if( row>=0 && row<n && col>=0 && col<m && !vi[row][col]&& image[row][col] == c)
            {
                dfs(row,col,color,image,vi,image[row][col]);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>>vi(n,vector<int>(m));
        dfs(sr,sc,color,image,vi,image[sr][sc]);
        
        return image;
        
    }
};