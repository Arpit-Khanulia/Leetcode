class Solution {
public:
    
    
    void solve(vector<vector<int>>&grid, vector<vector<int>>&vi,int r, int c, int &ans, int count){
        
        int n  = grid.size();
        int m  = grid[0].size();

        cout<<"    this is outside ->"<<r<<"-"<<c<<","<<count<<endl;
        
        if(grid[r][c] == 2 and count==-1) {
            ans++;
            return;
        }
        
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        
        for(int i =0; i<4;i++){
            
            int row = r + drow[i];
            int col = c + dcol[i];
            
            if(row>=0 and row< n and col>=0 and col< m and !vi[row][col] and grid[row][col] != -1){
                
                // cout<<"    this is inside ->"<<row<<" "<<col<<endl;
                vi[row][col] =1;
                solve(grid,vi,row,col,ans,count-1);
                vi[row][col] = 0;
            }
        }
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m  = grid[0].size();
        
        vector<vector<int>>vi(n,vector<int>(m));
        
        int r=0;
        int c =0;
        int ans =0;
        int count =0;
        
        for( int i=0; i<n;i++){
            for( int j =0; j<m;j++){
                
                if(grid[i][j] == 0) count ++;
                
                if(grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
            }
        }
        
        cout<<count<<endl;
        vi[r][c] =1;
        solve(grid,vi,r,c,ans,count);
        return ans;

    }
};