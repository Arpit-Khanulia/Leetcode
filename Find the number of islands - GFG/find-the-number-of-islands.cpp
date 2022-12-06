//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    // void bfs(int n, int m, vector<vector<char>>&grid,vector<vector<int>>&vi){

    //     vi[n][m] =1;

    //     int row = grid.size();
    //     int col = grid[0].size();

    //     queue<pair<int,int>>q;
    //     q.push({n,m});

        // while(!q.empty()){

        //     int temp1 = q.front().first;
        //     int temp2 = q.front().second;
        //     q.pop();
            
        //     for(int i = -1; i<=1; i++)
        //     for(int j = -1; j<=1; j++)
        //     {
        //         int nrow = temp1 +i;
        //         int mcol = temp2 +j;

                // if(nrow>=0 && nrow < row && mcol>=0 && mcol<col 
                // && vi[nrow][mcol] ==0 && grid[nrow][mcol] == '1')
                // {
                //     vi[nrow][mcol] =1;
                //     q.push({nrow,mcol});
                // }
        //     }

        // }


    // }
    
    int bfs(int k, int l, vector<vector<char>>&grid, vector<vector<int>>&vi){
        
        vi[k][l] =1;
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({k,l});
        
        while(!q.empty())
        {
            
            int temp1 = q.front().first;
            int temp2 = q.front().second;
            q.pop();
            
            for(int i =-1;i<=1;i++)
            for(int j =-1;j<=1;j++)
            {
                int nrow = temp1 + i;
                int mcol = temp2 +j;
                
                if(nrow>=0 && nrow < row && mcol>=0 && mcol<col 
                && vi[nrow][mcol] ==0 && grid[nrow][mcol] == '1')
                {
                    vi[nrow][mcol] =1;
                    q.push({nrow,mcol});
                }
                
            }
            
        }
        
    }
    
    
    //888888888888888888888888888888888888888888888884
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        
        vector<vector<int>>vi(n,vector<int>(m,0));
        
        for(int i =0; i<n; i++)
        for(int j =0; j<m; j++)
        {
            if(grid[i][j] == '1' && !vi[i][j])
            {
                count++;
                bfs(i,j,grid,vi);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends