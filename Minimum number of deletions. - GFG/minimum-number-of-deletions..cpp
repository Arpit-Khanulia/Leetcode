//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int find(string &a, string &b , int x, int y,vector<vector<int>>&dp ){

        if(x ==0 || y == 0 ) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        if(a[x-1] == b[y-1]) return dp[x][y] = 1+ find(a,b,x-1,y-1,dp);

        return dp[x][y]=  max(find(a,b,x-1,y,dp), find(a,b,x,y-1,dp));
}
int minDeletions(string str, int n) { 
    //complete the function here 
    
    string str2 = str;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    reverse(str2.begin(),str2.end());
    int lcs = find(str,str2,n,n,dp);
    return n - lcs;
} 