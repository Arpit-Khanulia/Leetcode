//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int n , int m, vector<vector<int>>&grid, vector<vector<int>>&vi, vector<pair<int,int>>&ds,int a, int b){
        
        vi[n][m] =1;
        ds.push_back({n-a,m-b});
        
        int sizen = grid.size();
        int sizem = grid[0].size();
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        for(int i=0; i<4; i++ )
        {
            int row = n + drow[i];
            int col = m + dcol[i];
            
            if(row<sizen && row>= 0 && col < sizem && col>=0 && !vi[row][col])
            {
                if(grid[row][col] == 1)
                dfs(row,col,grid,vi,ds,a,b);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vi(n,vector<int>(m));
        set<vector<pair<int,int>>>ans;
        
        
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m;j++){
                
                if(!vi[i][j] && grid[i][j] == 1 ){
                vector<pair<int,int>>ds;
                dfs(i,j,grid,vi,ds,i,j);
                ans.insert(ds);
                }
            }
        }
        
        return ans.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends