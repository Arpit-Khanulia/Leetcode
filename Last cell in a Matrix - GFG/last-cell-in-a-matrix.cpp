//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    pair<int,int> find(vector<vector<int>>&matrix, int r, int c,int d)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = r;
        int col = c;
        switch(d){
            case 0: col++;
            break;
            case 1: row++;
            break;
            case 2: col--;
            break;
            case 3: row--;
            break;
        }
        
        if(!(row <n && row>=0 && col<m && col>=0))
        {
            return {r,c};
        
        }
        if(matrix[row][col] == 0) return find(matrix,row,col,d);
        
        if(matrix[row][col] == 1)
        {
            matrix[row][col] =0;
            return find(matrix,row,col,(d+1)%4);
        }
        
    }
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        
        if(matrix[0][0] == 0)
        return find(matrix,0,0,0);
        
        return find(matrix,0,0,1);
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends