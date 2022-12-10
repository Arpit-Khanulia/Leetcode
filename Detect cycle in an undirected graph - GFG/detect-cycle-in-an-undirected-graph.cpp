//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
   int find(int node, vector<int>adj[],vector<int>&vi){
        
        queue<pair<int,int>>q;
        q.push({node,-1});
        vi[node] =1;
        
        while(!q.empty()){
            
            int temp = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(int i: adj[temp])
            {
                if(!vi[i])
                {
                    q.push({i,temp});
                    vi[i] =1;
                    
                }
                else if(i != parent)
                return 1;
            }
        
        }
        return 0;
        
        
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // code here
        vector<int>vi(V);
        
        for(int i =0;i<V;i++) {
            if(!vi[i]) {
                if(find(i, adj, vi)) return true; 
            }
        }
        return false; 
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends