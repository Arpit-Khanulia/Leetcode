class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int maxi =0;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vi(n,vector<int>(m));
        vector<vector<int>>distance(n,vector<int>(m,-1));
        
        queue<pair<pair<int,int>,pair<int,int>>>q;
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                
                if(grid[i][j] == 1)
                {
                    vi[i][j] =1;
                    q.push({{i,j},{i,j}});
                }
            }
        }
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,-1,0,1};
        
        while(!q.empty()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            
            int dr = q.front().second.first;
            int dc = q.front().second.second;
            
            q.pop();
            
            distance[r][c] = abs(dr -r) + abs(dc - c);
            
            for(int i=0; i<4;i++){
                
                int row = drow[i]+ r;
                int col = dcol[i]+ c;
                
                if(row>=0 and row<n and col>= 0 and col<m and !vi[row][col] and grid[row][col] == 0)
                {   
                    vi[row][col] =1;
                    q.push({{row,col},{dr,dc}});
                }
 
            }      
            
        }
        
        for(int i=0; i<n;i++){
            for(int j =0; j<m;j++){
                maxi = max(maxi,distance[i][j]);
            }
        }
        
        if(maxi == 0) return -1;
        return maxi;
    }
};