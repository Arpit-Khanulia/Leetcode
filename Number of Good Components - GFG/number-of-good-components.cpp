//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int& node , vector<vector<int>>&adj,vector<int>&vi ,int &ver, int &edg){
        
        vi[node] =1;
        
        ver++;
        
        for(auto i: adj[node]){
            
            edg++;
            if(!vi[i]){
                dfs(i,adj,vi,ver,edg);
            }
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        
        vector<int>vi(V+1);
        int ans=0;
        
        for( int  i=1; i<=V;i++){
            
            if(!vi[i]){
                
                int ver=0;
                int edg=0;
                dfs(i,adj,vi,ver,edg);
                int temp = ver * (ver-1);
                if(edg == temp) ans++;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends