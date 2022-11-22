//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int find(string &a, string &b, int x, int y, vector<vector<int>>&dp){
	        
	        if(x == 0 || y == 0) return 0;
	        
	        if(dp[x][y] != -1) return dp[x][y];
	        
	        if(a[x-1] == b[y-1] && x!=y) return dp[x][y] = 1+ find(a,b,x-1,y-1,dp);
	        return dp[x][y] = max(find(a,b,x-1,y,dp),find(a,b,x,y-1,dp));
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    string str1 = str;
		    int n = str.size();
		    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		    
		    return find(str,str1,n,n,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends