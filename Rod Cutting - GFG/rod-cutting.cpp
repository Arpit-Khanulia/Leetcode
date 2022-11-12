//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int find(int price[],vector<int>arr,int sum, int n, vector<vector<int>>&dp){
        
        
        if( n==0 || sum ==0) return 0;
        
        if(dp[n][sum] !=-1) return dp[n][sum];
        
        
        if(arr[n-1] <= sum)
        {
            return dp[n][sum] =  max(price[n-1] + find(price, arr,sum - arr[n-1], n,dp) , find(price,arr,sum,n-1,dp) ); 
        }
        
        return dp[n][sum] = find(price,arr, sum,n-1,dp);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int>arr;
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        
        for(int i =1; i<=n;i++)
        arr.push_back(i);
        
        return find(price,arr,n,n,dp);
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