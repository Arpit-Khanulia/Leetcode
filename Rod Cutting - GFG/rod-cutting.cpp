//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int find(int n,int sum,int price[],vector<vector<int>>&dp){
        
        if(n == 0 || sum == 0) return 0;
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(n <= sum)
        return dp[n][sum] = max( price[n-1] + find(n,sum- n,price,dp) , find(n-1,sum,price,dp));
        return dp[n][sum] = find(n-1,sum,price,dp);

    }
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(n,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends