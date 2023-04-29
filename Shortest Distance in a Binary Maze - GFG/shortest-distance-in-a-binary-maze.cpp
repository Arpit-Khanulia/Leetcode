//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        queue< pair< int,pair<int,int> > >q;
        q.push({0,source});
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>distance(n+1,vector<int>(m+1,1e9));
        distance[source.first][source.second] =0;
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        
        while(!q.empty()){
            
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            if(row == destination.first and col == destination.second) return dist;
            
            for(int i=0; i<4;i++){
                
                int r  = drow[i] + row;
                int c =  dcol[i] + col;
                
                if( r<n and r>=0 and c<m and c>=0 and grid[r][c] and distance[r][c] > (dist +1) ){
                    
                    distance[r][c] = dist +1;
                    q.push({dist+1,{r,c}});
                    
                    
                }
            }
            
            
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends