//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int find(string &a, string &b, int x, int y, vector<vector<int>>&dp){
        
        if(x == 0|| y ==0 ) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        
        if(a[x-1] == b[y-1]) return dp[x][y] = 1+ find(a,b,x-1,y-1,dp);
        return dp[x][y] = max(find(a,b,x-1,y,dp),find(a,b,x,y-1,dp));
    }
    int findMinInsertions(string S){
        // code here 
        
        
        int n = S.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        string a = S;
        reverse(a.begin(),a.end());
        
        return n-find(S,a,n,n,dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends