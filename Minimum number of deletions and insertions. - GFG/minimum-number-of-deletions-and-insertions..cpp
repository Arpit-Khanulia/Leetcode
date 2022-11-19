//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int find(string a, string b , int x, int y,vector<vector<int>>&dp ){

        if(x ==0 || y == 0 ) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        if(a[x-1] == b[y-1]) return dp[x][y] = 1+ find(a,b,x-1,y-1,dp);

        return dp[x][y]=  max(find(a,b,x-1,y,dp), find(a,b,x,y-1,dp));
    }
    
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int x = str1.size();
	    int y = str2.size();
	    vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
	    int lcs = find(str1,str2,x,y,dp);
	    return x - lcs + y - lcs;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends