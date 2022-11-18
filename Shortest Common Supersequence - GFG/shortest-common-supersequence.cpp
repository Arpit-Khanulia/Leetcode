//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    
    int find(string a,string b, int m, int n, vector<vector<int>>&dp){
        
        if(m ==0 || n == 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(a[m-1] == b[n-1]) return dp[m][n] = 1+ find(a,b,m-1,n-1,dp);
        return dp[m][n] = max(find(a,b,m,n-1,dp), find(a,b,m-1,n,dp));
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return m+n -  find(X,Y,m,n,dp);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends