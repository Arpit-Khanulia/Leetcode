//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    long long find(vector<long long>&dp,vector<long long>&GeekNum,int n){
        
        if(n<= GeekNum.size())
        return GeekNum[n-1];
        
        if(dp[n] != -1) return dp[n];
        
        long long next = 0;
        
        for(int i=1;i<=GeekNum.size();i++){
            
            next += find(dp,GeekNum,n-i);
        }
        
        return dp[n] =  next;
    }
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        
        
        vector<long long >dp(N+1,-1);
        return find(dp,GeekNum,N);
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends