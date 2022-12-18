//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int bfs(vector<int>adj[],vector<int>&col,int node, int color){
        
        col[node] = color;
        
        queue<pair<int,int>>q;
        q.push({node,color});
        
        while(!q.empty())
        {
            int a = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
        
            for(int &i: adj[a]){

                if(col[i] ==-1) {
                    
                    col[i] = !c;
                    q.push({i,!c});
                }
                else if(c == col[i]) return false;
                
                
            }
        
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>col(V,-1);
	    for(int i =0; i<V;i++)
	    if(col[i] == -1) if(bfs(adj,col,i,1) == false) return false;
	    
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