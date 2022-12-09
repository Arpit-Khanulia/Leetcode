//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vi(n,vector<int>(m,0));
        
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i =0; i<n;i++)
        for(int j =0; j<m;j++)
        if(grid[i][j] == 2)
        {
            q.push({{i,j},0});
            vi[i][j] =1;
        }
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        
        int maxt =0;
        
        while(!q.empty()){
            
            int a= q.front().first.first;
            int b= q.front().first.second;
            int t= q.front().second;
            
            maxt= max(maxt,t);
            q.pop();
            
            for(int i=0; i<4;i++)
            {
                int row = a + drow[i];
                int col = b + dcol[i];
                
                if(row>=0 && row<n && col>=0 && col<m &&  !vi[row][col] && grid[row][col] == 1){
                    q.push({{row,col},t+1});
                    vi[row][col] =1;
                    grid[row][col] = 2;
                }
            }
            
            
        }
        
        for(int i =0; i<n;i++)
        for(int j =0; j<m;j++)
        if(grid[i][j] == 1) return -1;
        
        return maxt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends