//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
	    vector<int>id(V);
	    for(int i=0; i<V;i++)
	    for(int j:adj[i])
	    id[j]++;
	    
	    queue<int>q;
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++)
	    if(id[i]== 0) q.push(i);
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for(int i: adj[node])
	        {
	           id[i]--;
	           if(id[i] == 0) q.push(i);
	        }
	    }
	    
	    if(ans.size() == V) return false;
	    return true;
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