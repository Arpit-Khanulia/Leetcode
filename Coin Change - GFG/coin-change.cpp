//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long find(int coins[], int sum, vector<vector<long long>>&dp,long long n){
        
        if(n ==0){
            if(sum ==0) return 1;
            return 0;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        
        if(coins[n-1] <= sum )
        return dp[n][sum]=  find(coins,sum-coins[n-1],dp,n) + find(coins,sum,dp,n-1);
        return dp[n][sum]=  find(coins,sum,dp,n-1);
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<vector<long long>>dp(N+5,vector<long long >(sum+5,-1));
        return  find(coins,sum,dp,N);
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