//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int ispalindrome(string str,int i, int j){
        
        
        while(i<j)
        {
            if(str[i] != str[j])
            return 0;
            
            i++;
            j--;
        }
        
        return 1;
        
        
    }
    
    int find(string &str,int i , int j,vector<vector<int>>&dp){
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i>=j) return 0;
        
        if(ispalindrome(str,i,j)) return 0;
        
        
        int mini = INT_MAX;
        for(int k =i; k<j;k++)
        {
            int a = find(str,i,k,dp);
            int b = find(str,k+1,j,dp);
            
            int temp = 1 + a+b;
            
            mini = min(mini,temp);

        }
        
        return dp[i][j]  =mini;
        
    }
    int palindromicPartition(string str)
    {
        // code here
        
        int n = str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(str,0,n-1,dp);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends