//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0; i<edges.size();i++){
            
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        
        vector<int>distance(n+1,1e9),parent(n+1);
        
        for( int i=1; i<=n;i++)
        parent[i] =i;
        

        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        q.push({0,1});
        distance[1] =0;
        vector<int>ans;
        
        while(!q.empty()){
            
            int d = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto i : adj[node]){
                
                int d2 = i.second;
                int node2 = i.first;
                int newd = d + d2;
                
                if(newd < distance[node2]){
                    
                    distance[node2] = newd;
                    parent[node2] = node;
                    q.push({newd,node2});
                }
            }
            
        }
        
        
        if(distance[n] == 1e9) return {-1};
        int node = n;
        
        while(parent[node] != node){
            
            ans.push_back(node);
            node = parent[node];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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