//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>vi(n,vector<int>(m));
	    vector<vector<int>>ans(n,vector<int>(m));
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    
	    for(int i =0; i<n;i++)
	    for(int j =0; j<m;j++){
	        
	        if(grid[i][j] == 1)
	        {
	            q.push({{i,j},0});
	            vi[i][j] =1;
	        }
	    }
	    
	    
	    int drow[] ={1,0,-1,0};
	    int dcol[] ={0,1,0,-1};
	    
	    while(!q.empty()){
	        
	        int a = q.front().first.first;
	        int b = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        
	        
	        ans[a][b] = d;
	        
	        for(int i =0; i<4;i++)
	        {
	            int row = a + drow[i];
	            int col = b + dcol[i];
	            
	            
	            if(row>=0 && row<n && col>= 0 && col<m && !vi[row][col] )
	            {
	                vi[row][col] =1;
	                q.push({{row,col},d+1});
	        
	            }
	        }
	        
	        
	    }
	    
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends