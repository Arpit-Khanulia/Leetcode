//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  
    int find(int arr[], vector<vector<int>>&dp,int target,int n){
        
        if(target == 0) return dp[n][target] = 1;
        if(n == 0 ) return dp[n][target] = 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int ans1 =0;
        if(arr[n] <= target){
            ans1 = find(arr,dp,target - arr[n],n-1);
        }
        
        int ans2 = find(arr,dp,target,n-1);
        
        return dp[n][target] = ans1 || ans2;
        
        
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum =0;
	    for(int i=0; i<n;i++) sum += arr[i];
	    
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    
	    for(int i=0; i<= sum;i++)
	    find(arr,dp,i,n-1);
	    
	    int mini = INT_MAX;
	    for(int i=0; i<dp.size();i++)
	    for(int j =0; j<dp[0].size();j++){
	        
	        if(dp[i][j] == 1){
           
	            mini = min(mini, abs((sum-j) -j ));
	        }
	    }

	    
	    return mini;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends