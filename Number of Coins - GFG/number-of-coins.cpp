//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
    long long find(int coins[], int n, int sum, vector<vector<long long>>&dp)
    {
        if(n == 0)
        {
            if( sum == 0) return 0;
            if(sum <= 0 ) return INT_MAX -1;
            return INT_MAX-1;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(coins[n-1] <= sum )
        {
            int l =  1+ find(coins, n, sum- coins[n-1],dp);
            int r =  find(coins,n-1,sum,dp);
            

            return dp[n][sum] = min(l,r);
        }
        return dp[n][sum] = find(coins,n-1,sum,dp);
    }
    
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
        vector<vector<long long>>dp(M+1,vector<long long>(V+1,-1));
        int a = find(coins,M,V,dp);
        if(a == INT_MAX-1) return -1;
        return a;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends