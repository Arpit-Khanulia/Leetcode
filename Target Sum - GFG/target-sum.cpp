//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
    int find(vector<int>&a,int target,int n , vector<vector<int>>&dp)
    {
        if(n ==0)
        {
            if( target == 0) return 1;
            return 0;
        }
        
        if(dp[n][target ]  != -1) return dp[n][target];
        
        
        if(a[n-1]<= target)
        {
            return dp[n][target] = find(a,target - a[n-1],n-1,dp) + find(a,target,n-1,dp);
            
        }
        
        return dp[n][target] = find(a, target, n-1,dp);
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int sum =0;
        for(int i:A)
        sum = sum + i;
        
        if((sum-target)%2 || sum < target) return 0;
        target = (sum - target)/2;
        
        vector<vector<int>>dp(A.size() +1 , vector<int>(target +1,-1));
        return find(A,target,A.size(),dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends