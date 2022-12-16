//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(int n, int m, int color, vector<vector<int>>&image,vector<vector<int>>&vi,int newcolor){
        
        vi[n][m] =1;
        image[n][m] = newcolor;
        int sizen = image.size();
        int sizem = image[0].size();
        
        int drow[] ={1,0,-1,0};
        int dcol[] ={0,1,0,-1};
        
        for(int i=0; i<4;i++){
            
            int row = n + drow[i];
            int col = m + dcol[i];
            
            if(row<sizen && row>= 0 && col<sizem && col>=0 && !vi[row][col] && image[row][col] == color )
            dfs(row,col,color,image,vi,newcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        
        vector<vector<int>>vi(n,vector<int>(m));
        
        dfs(sr,sc,color,image,vi,newColor);
        
        return image;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends