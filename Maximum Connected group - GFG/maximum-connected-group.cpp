//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,-1,0,1};
        
        DisjointSet ds(n*m);
        
        for(int i=0; i<n;i++){
            
            for(int j =0; j<m;j++){
                
                if(grid[i][j] == 1){
                    
                    for(int k=0; k<4; k++){
                        
                        int row = drow[k] +i;
                        int col = dcol[k] +j;
                        
                        if(row>=0 and row<n and col>=0 and col<m and grid[row][col]){
                            
                            int up1 = i*m + j;
                            int up2 = row*m + col;
                            if(ds.findUPar(up1) != ds.findUPar(up2)){
                                ds.unionBySize(up1,up2);
                            }
                            
                        }
                    }
                }
            }
        }
        
        int maxi =0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0; j<m;j++){
                
                int sum =0;
                set<int>s;
                if(grid[i][j] == 0){
                    
                    for(int k =0; k<4;k++){
                        
                        int row = drow[k] + i;
                        int col = dcol[k] + j;  
                        
                        if(row>=0 and row<n and col>=0 and col<m and grid[row][col] ==1){
                            
                            int up22 = row*m + col;
                            s.insert(ds.findUPar(up22));
                        }
                    }            
                    
                }
                
                for(auto a : s){
                    
                    sum = sum + ds.size[a];
                }
                
                maxi = max(maxi,sum+1);
            }
        }
        
        
        maxi = max(maxi, ds.size[ds.findUPar(grid[0][0])]);

        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends