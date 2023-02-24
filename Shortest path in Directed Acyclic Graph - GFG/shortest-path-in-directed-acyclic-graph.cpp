//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void toposort(vector<pair<int,int>>adj[],stack<int>&topo,vector<int>&vi,int node){
        
        vi[node] =1;
        
        for(auto i: adj[node]){
            
            if(!vi[i.first]) toposort(adj,topo,vi,i.first);
        }
        
        topo.push(node);
        
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        stack<int>topo;
        vector<pair<int,int>>adj[N];
        vector<int>vi(N);
        
        for(int i=0; i<M;i++){
            
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        
        for(int i =0; i<N; i++)
        if(!vi[i]) toposort(adj,topo,vi,i);
        
        
        vector<int>distance(N,1e9);
        distance[0] =0;
        
        while(!topo.empty()){
            
            int temp = topo.top();
            topo.pop();
            
            for(auto i: adj[temp]){
                
                int n = i.first;
                int d = i.second;
                
                if(distance[temp] + d < distance[n])
                distance[n] = distance[temp] +d;
            }
         
        }
        
        for(int i=0; i<N;i++)
        if(distance[i] == 1e9) distance[i] = -1;
        
        
        return distance;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends