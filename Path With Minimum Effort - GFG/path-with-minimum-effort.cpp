//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        
        q.push({0,{0,0}});
        
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        distance[0][0] = 0;
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,-1,0,1};
        
        
        while(!q.empty()){
            
            int effort = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            
            if(row == n-1 and col == m-1) return effort;
            
            for(int i=0; i<4;i++){
                
                int r = drow[i] + row;
                int c = dcol[i] + col;
                
                
                if(r >=0 and r<n and c>=0 and c<m){
                    
                    int d= max(effort,abs(heights[r][c] - heights[row][col]));
                    
                    if(distance[r][c] > d ){
                        
                        q.push({d,{r,c}});
                        distance[r][c] = d ;            
                        
                    }
                    
                }
            }
            
            
        }
        
        return 0;
        // return distance[n-1][m-1]; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends