//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    long long find(int i,int r[],int g[],int b[],int p,int n,vector<vector<long long >>&dp){
        
        if(i == n) return 0;
        
        if(dp[i][p]!= -1) return dp[i][p];
        
        long long  x=LONG_MAX ,y=LONG_MAX,z=LONG_MAX;
        
        if(p!= 1) x= r[i] + find(i+1,r,g,b,1,n,dp);
        if(p!= 2) y= g[i] + find(i+1,r,g,b,2,n,dp);
        if(p!= 3) z= b[i] + find(i+1,r,g,b,3,n,dp);
        
        x = min(x,y);
        return dp[i][p] = min(x,z);
        
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        
        vector<vector<long long>>dp(N,vector<long long>(4,-1));
        return find(0,r,g,b,0,N,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends