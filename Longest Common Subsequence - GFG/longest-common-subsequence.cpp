//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int find (string a, string b, int x,int y, vector<vector<int>>&dp){
        
        if(x ==0 || y == 0) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        
        
        if(a[x-1] == b[y-1]) return dp[x][y] = 1+ find(a,b,x-1,y-1,dp);
        
        return dp[x][y] = max(find(a,b,x-1,y,dp),find(a,b,x,y-1,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        
        return find(s1,s2,x,y,dp);
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends