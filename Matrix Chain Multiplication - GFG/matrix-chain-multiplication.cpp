//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int find(int arr[],int i , int j,vector<vector<int>>&dp){
        
        if(j<= i) return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for(int k = i; k<j;k++)
        {
            
            int a =find(arr,i,k,dp);
            int b =find(arr,k+1,j,dp); 
            int cost = a+b+ arr[i-1] * arr[k] * arr[j];
            
            mini = min(mini , cost);
            
        }
        
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        int i =1;
        int j =N-1;
        
        return find(arr,i,j,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends