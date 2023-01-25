class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vi(n,vector<int>(m));
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j] == 2 ){
                    vi[i][j] =1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,-1,0,1};
        
        int totaltime =0;
        
        while(!q.empty()){
            
            
            
            int i= q.front().first.first;
            int j= q.front().first.second;
            int time = q.front().second;
            
            totaltime = max(time,totaltime);
            
            vi[i][j] =1;
            q.pop();
            
            for(int k=0; k<4;k++){
                
                int row = i+drow[k];
                int col = j+dcol[k];
                
                if(row<n && row>=0 && col<m && col>=0 && !vi[row][col] && grid[row][col] == 1){
                    
                    vi[row][col] =1;
                    grid[row][col] = 2;
                    q.push({{row,col},time+1});
                }
            }
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                
                if(grid[i][j] == 1) return -1;
            }
        }
        
        
        
        return totaltime;
    }
};