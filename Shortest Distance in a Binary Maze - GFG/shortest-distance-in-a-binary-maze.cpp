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
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vi(n,vector<int>(m));
        
        q.push({source,0});
        vi[source.first][source.second] =1;
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,-1,0,1};
        
        
        while(!q.empty()){
            
            int i = q.front().first.first;
            int j = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            if(i == destination.first and j == destination.second) return steps;
            
            for(int a=0; a<4;a++){
                
                int row = i + drow[a];
                int col = j + dcol[a];
                
                if(row>= 0 and row<n and col>=0 and col<m and !vi[row][col] and grid[row][col]){
                    vi[row][col]= 1;
                    q.push({{row,col},steps+1});
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