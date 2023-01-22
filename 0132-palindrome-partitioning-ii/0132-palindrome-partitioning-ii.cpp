class Solution {
public:
    int ispallindrome(string &s, int i, int j){
        
        while(i<=j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        
        return 1;
    }
    
    int find(string &s, int start, int end,vector<vector<int>>&dp){
        
        
        if(dp[start][end] != -1) return dp[start][end];
        if(start>=end) return 0;
        
        if(ispallindrome(s,start,end)) return 0;
        
        int mini = INT_MAX;
        for(int k =start; k<end;k++){
            int total;
            if(ispallindrome(s,start,k)) total = find(s,k+1,end,dp) + 1;

            mini = min(mini,total);
        }
        
        return dp[start][end] = mini;
    }
        
    int minCut(string s) {
        
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return find(s,0,s.size()-1,dp);
        
    }
};