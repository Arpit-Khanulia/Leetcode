//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    int dfs(vector<int>adj[],vector<int>&dfsvi,vector<int>&vi,int node){
        
        vi[node] =1;
        dfsvi[node] =1;
        
        
        for(int &i: adj[node]){
            
            if(vi[i] ==0){
                
                if(dfs(adj,dfsvi,vi,i) == true) return true;
            }
            else if(dfsvi[i] == 1) return true;
        }
        
        dfsvi[node] =0;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>vi(V);
        vector<int>dfsvi(V);
        
        for(int i=0; i<V;i++)
        if(vi[i] == 0) if(dfs(adj,dfsvi,vi,i) == true) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends