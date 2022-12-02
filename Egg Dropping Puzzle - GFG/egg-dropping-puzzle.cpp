//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<vector<int>>dp(202,vector<int>(202,-1));
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        
        if(n ==1) return k;
        
        if(k <=1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mini = INT_MAX;
        
        for(int i =1; i<=k;i++)
        {
            int temp  = 1+ max( eggDrop(n-1,i-1) , eggDrop(n,k-i) );
            mini = min(temp,mini);
        }
        
        return dp[n][k] = mini;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends