//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
	int find(string &a, string &b , int x, int y,vector<vector<int>>&dp ){

        if(x ==0 || y == 0 ) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        if(a[x-1] == b[y-1]) return dp[x][y] = 1+ find(a,b,x-1,y-1,dp);

        return dp[x][y]=  max(find(a,b,x-1,y,dp), find(a,b,x,y-1,dp));
    }
    
    
    int longestPalinSubseq(string A) {
        //code here
        

        string b;
        int x = A.size();


        for(int i =x-1; i>= 0;i--)
        b.push_back(A[i]);

        vector<vector<int>>dp(x+1,vector<int>(x+1,-1));
        return find(A,b,x,x,dp);
        
        
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends