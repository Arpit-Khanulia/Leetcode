//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dfs(vector<int>adj[],vector<int>&vi,vector<int>&dfsvi,vector<int>&ds,int node){
        
        vi[node] =1;
        dfsvi[node] =1;
        // ds[node] =0;
        
        for(int &i: adj[node]){
            
            
            if(vi[i] == 0)
            {
                
                if(dfs(adj,vi,dfsvi,ds,i) == false ) return false;
            }
            else if(dfsvi[i] == 1) return false;
        }
        
        ds[node] =1;
        dfsvi[node] =0;
        return true;
    }
  
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int>vi(V);
        vector<int>dfsvi(V);
        vector<int>ds(V,0);
        vector<int>ans;
        
        for(int i =0; i<V;i++)
        if(vi[i] == 0 ) dfs(adj,vi,dfsvi,ds,i);
        
        for(int i =0; i<V;i++)
        if(ds[i] == 1) ans.push_back(i);
        
        sort(ans.begin(),ans.end());
        
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends