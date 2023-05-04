//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


vector<int>parent(1000);
vector<int>size(1000,1);


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	int findparent(int node){
	    
	    if(parent[node] == node) return node;
	    
	    return parent[node] = findparent(parent[node]);
	}
	
	void disjointunion(int a, int b){
	    
	    int ulpa = findparent(a);
	    int ulpb = findparent(b);
	    
	    if(ulpa == ulpb) return;
	    
	    if(size[ulpa] < size[ulpb]){
	        
	        parent[ulpa] = ulpb;
	        size[ulpb] += size[ulpa];
	    }
	    else{
	        
	        parent[ulpb] = ulpa;
	        size[ulpa] += size[ulpb];
	    }
	    
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        for(int i=0; i<1000; i++) parent[i] =i;
        
        int mstw =0;
        vector<pair<int,pair<int,int>>>edges;
        
        for(int i=0;i<V;i++)
        for(auto j: adj[i]) edges.push_back({j[1],{i,j[0]}});
        
        sort(edges.begin(),edges.end());
        
        for(auto i: edges){
            
            int a = i.second.first;
            int b = i.second.second;
            
            if(findparent(a) != findparent(b)) 
            {
                disjointunion(a,b);
                mstw += i.first;
            }
        }
        
        return mstw;
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends