// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool isSubsetSum(vector<int>arr, int sum){
        
        
    //     vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1));
        
    //     for(int i =0; i<arr.size()+1;i++)
    //     for(int j =0;j<sum+1;j++)
    //     {
    //         if(i == 0)
    //         dp[i][j]=0;
            
    //         if(j ==0)
    //         dp[i][j]= 1;
            
            
    //     }
        

        
    //     for(int i =1 ;i< arr.size()+1;i++)
    //     for(int j = 1;j<sum +1;j++)
    //     {
    //         if(arr[i-1]<=j)
    //         dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
    //         else dp[i][j] = dp[i-1][j];
    //     }
        

        
    //     return dp[arr.size()][sum];
    // }
    
    int find(vector<int>arr,int sum,int n , vector<vector<int>>&dp)
    {
        if(sum == 0) return 1;
        
        if(n <= 0) return 0;
        
        if(dp[sum][n] != -1) return dp[sum][n];
        
        if(arr[n-1] <= sum)
        {
            int take = find(arr,sum - arr[n-1],n-1,dp);
            int nottake = find(arr, sum , n-1, dp);
            
            return dp[sum][n] =  take || nottake;
        }
        
        return dp[sum][n] =  find(arr,sum, n-1,dp);
        
        
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        
        vector<vector<int>>dp(sum+5, vector<int>(arr.size() + 5,-1 ));
        
        return find(arr,sum,arr.size(),dp);
    }
};



// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends