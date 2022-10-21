//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int find(int n, int sum, int val[],int wt[],vector<vector<int>>&dp){
        
        
        if(n ==0 || sum == 0) return 0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(wt[n-1]<=sum)
        return dp[n][sum] = max(val[n-1] + find(n,sum-wt[n-1],val,wt,dp) , find(n-1,sum,val,wt,dp));
        return find(n-1,sum,val,wt,dp);
        
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        
        return find(N,W,val,wt,dp);
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends