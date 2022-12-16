//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int dfs(int node, vector<int>&col,vector<int>adj[],int color){
        
        col[node] = color;
        
        for(int &i:adj[node]){
            
            if(col[i] == -1)
            {
                if(dfs(i,col,adj,!color) == false) return false;
            }
            else if(col[i] == color) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>col(V,-1);
	    for(int i =0; i<V;i++)
	    if(col[i] == -1) if(dfs(i,col,adj,1) == false) return false;
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends