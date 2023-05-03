//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     
                    vector<vector<int>>adjmat(n,vector<int>(n,1e9));
                     
                    for(int i=0; i<m;i++)
                    {
                        adjmat[edges[i][0]][edges[i][1]] = edges[i][2];
                        adjmat[edges[i][1]][edges[i][0]] = edges[i][2];
                        
                    }
                    
                    for(int i=0; i<n;i++) adjmat[i][i] =0;
                    
                    for(int k=0 ;k<n; k++){
                        
                        for(int i =0; i<n;i++){
                            
                            for(int j =0; j<n;j++){
                                
                                if(adjmat[i][k] == 1e9 || adjmat[k][j] == 1e9) continue;
                                adjmat[i][j] = min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
                                
                            }
                        }
                    }
                    
                    
                    int ans =0;
                    int min = INT_MAX;
                    for(int i =0; i<n;i++){
                        
                        int a=0; 
                        for(int j =0; j<n;j++){
                            
                            if(adjmat[i][j] <= distanceThreshold ) a++;

                        }
                        
                        if(a<=min) {
                            min = a;
                            ans = i;
                        }
                    }
                    
                    return ans;
                    
                    
                    
                    
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends