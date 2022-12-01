//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int find(string &s,int i ,int j , int istrue,vector<vector<vector<int>>>&dp){
        
        if(i>j) return 0;
        
        
        
        if(i ==j )
        {
            if(istrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
        int ans =0;
        for(int k=i+1; k<j;k+=2)
        {
            int lt = find(s,i,k-1,1,dp);
            int lf = find(s,i,k-1,0,dp);
            int rt = find(s,k+1,j,1,dp);
            int rf = find(s,k+1,j,0,dp);
            
            
            if(s[k] == '&')
            {
                if(istrue == 1) ans = ans + (lt* rt)%mod;
                else ans = ans + (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod;
                
            }
            else if(s[k] == '^')
            {
                if(istrue == 1) ans = ans +  (lt*rf)%mod + (lf*rt)%mod;
                else ans = ans +  (lt*rt)%mod + (lf*rf)%mod;
                
            }
            
            else if(s[k] == '|')
            {
                if(istrue == 1) ans = ans +  (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod;
                else ans = ans + (lf*rf)%mod;
            }
            
            
        }
        return dp[i][j][istrue] = ans%mod;
        
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(3,-1)));
        return find(S,0,N-1,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends