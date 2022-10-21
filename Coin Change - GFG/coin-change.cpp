//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long find(int n, int target,int coins[],vector<vector<long long >>&dp){
        
        if(n ==0)
        {
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp[n][target] != -1) return dp[n][target];
        
        if(coins[n-1] <= target)
        return dp[n][target] = find(n,target - coins[n-1],coins,dp) + find(n-1,target,coins,dp);
        return dp[n][target] = find(n-1,target,coins,dp);
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<vector<long long >>dp(N+1,vector<long long>(sum+1,-1));
        return find(N,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends