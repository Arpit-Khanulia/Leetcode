//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
     void dfs(int node, vector<int>&vi,vector<int>adj[]){
        vi[node] =1;
        
        for(int i: adj[node]){
            
            if(!vi[i]) dfs(i,vi,adj);
        }
        
    }
    
    int Solve(int n, vector<vector<int>>& connections) {
        // code here
        
        int k  = connections.size();
        if(k < n-1) return -1;
        
        vector<int>vi(n);
        vector<int>adj[n];
        
        for(auto i : connections){
            
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int count=0;
        
        for(int i=0; i<n;i++){
            
            if(!vi[i]){
                dfs(i,vi,adj);
                count++;
                
            }
            
        }
        
        return count -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends