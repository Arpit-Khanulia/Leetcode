//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int n, int m, vector<vector<int>>&grid, vector<vector<int>>&vi){
        
        vi[n][m] =1;
        
        int sizen = grid.size();
        int sizem = grid[0].size();
        
        int drow [] ={1,0,-1,0};
        int dcol [] ={0,-1,0,1};
        
        for(int i=0; i<4;i++){
            
            int row = n + drow[i];
            int col = m + dcol[i];
            
            if(row>=0 && row<sizen && col>=0 && col<sizem && !vi[row][col]){
                
                
                if(grid[row][col] == 1)
                dfs(row,col,grid,vi);
                
                
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vi(n,vector<int>(m));
        for(int i = 0 ; i< n;i++){
            
            if(grid[i][0] == 1)
            dfs(i,0,grid,vi);
            
            if(grid[i][m-1] == 1)
            dfs(i,m-1,grid,vi);
        }
        
        for(int j =0 ; j<m; j++){
            
            if(grid[0][j] == 1)
            dfs(0,j,grid,vi);
            
            if(grid[n-1][j] == 1)
            dfs(n-1,j,grid,vi);
        }
        
        
        int count = 0;
        for(int i=0 ; i<n;i++){
            for(int j =0; j<m; j++){
                
                if(grid[i][j] == 1 && !vi[i][j])
                count ++;
            }
        }
        
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends