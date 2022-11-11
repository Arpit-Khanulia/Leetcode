//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
        // prac 1
        
        // int find(int w, int wt[],int val[],int n , vector<vector<int>>&dp)
        // {
        //     if(n < 0 || w == 0)
        //     return 0;
            
        //     if(dp[w][n] != -1) return dp[w][n];
            
            
        //     if(wt[n] <= w)
        //     {
        //         int left = val[n] + find(w-wt[n],wt,val,n-1,dp);
        //         int right =  find(w,wt,val,n-1,dp);
                
        //         return dp[w][n] = max(left,right);
                
        //     }
    
        //     return dp[w][n] =  find(w,wt,val,n-1,dp);
            
        // }
        // int knapSack(int W, int wt[], int val[], int n) 
        // { 
        //   // Your code here
           
        //   vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
        //   return find(W,wt,val,n-1,dp);
        // }
    
    
    
        // prac 2
        // int knapSack(int W, int wt[], int val[], int n) 
        // { 
        //   // Your code here
           
        //   vector<vector<int>>dp(n+1,vector<int>(W+1));
           
        //   for(int i =0; i<n+1;i++)
        //   for(int j =0; j<W+1;j++)
        //   if(i == 0 || j == 0)
        //   dp[i][j] = 0;
           
           
        //   for(int i=1; i<n+1;i++)
        //   {
        //       for(int j =1; j<W+1;j++)
        //       {
                   
        //           if(wt[i-1] <= j)
        //           dp[i][j] = max( val[i-1] + dp[i-1][j - wt[i-1]] , dp[i-1][j]);
        //           else dp[i][j] = dp[i-1][j];
                   
    
        //       }
        //   }
           
        //   return dp[n][W];
           
        // }
    
    
    int find(int w , int wt[], int val[], int n, vector<vector<int>>&dp){
        
        if(n == 0 || w == 0) return 0;
        
        if(dp[w][n] != -1) return dp[w][n];
        
        if(wt[n-1] <= w )
        {
            int include  = val[n-1] + find(w-wt[n-1],wt,val,n-1,dp);
            int notinclude = find(w,wt,val,n-1,dp);
            
            return dp[w][n] = max(include,notinclude);
        }
        
        return dp[w][n] = find(w,wt,val,n-1,dp);
    }
    int knapSack(int W, int wt[], int val[], int n) {
        
        vector<vector<int>>dp(W+5,vector<int>(n+5,-1));
        return find(W,wt,val,n,dp);
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends