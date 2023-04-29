//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>>adj[n+1];
        
        for(int i =0;i<edges.size();i++){
            
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,1});
        
        vector<int>parent(n+1);
        parent[1] =1;
        
        vector<int>distance(n+1,1e9);
        distance[1] =0;
        
        while(!q.empty()){
            
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto i: adj[node]){
                
                int d = dist + i.second;
                if(distance[i.first] > d){
                    
                    distance[i.first] =d;
                    q.push({d,i.first});
                    parent[i.first] = node;
                }
            }
            
            
        }
        
        if(distance[n] == 1e9) return {-1};        
        
        vector<int>ans;

        int i = n;
        while(parent[i]!=i){
            
            ans.push_back(i);
            i = parent[i];
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