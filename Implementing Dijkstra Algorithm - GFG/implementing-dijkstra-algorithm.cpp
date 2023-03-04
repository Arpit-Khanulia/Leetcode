//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        set<pair<int,int>>s;
        
        s.insert({0,S});
        
        vector<int>distance(V,INT_MAX);
        distance[S]=0;
        
        while(!s.empty()){
            
            auto temp = *s.begin();
            int dist = temp.first;
            int node = temp.second;
            s.erase(temp);
            
            for(auto i: adj[node]){
                
                int d = i[1];
                int n = i[0];
                
                int newd = dist + d;
                
                if(newd < distance[n]){
                    
                    if(distance[n] != INT_MAX) s.erase({distance[n],n});
                    
                    distance[n] = newd;
                    s.insert({newd,n});
                }
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends