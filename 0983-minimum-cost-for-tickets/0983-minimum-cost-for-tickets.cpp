class Solution {
public:
    int n;
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int> &dp) {
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];

        int i;
        int op1 = costs[0] + solve(days, costs, idx+1, dp);
        
        i=idx;
        while(i<n && days[i]<days[idx]+7){
            i++;
        }
        
        int op2 = costs[1] + solve(days, costs, i, dp);
        
    
        i=idx;
        while(i<n && days[i]<days[idx]+30){
            i++;
        }
            
        int op3 = costs[2] + solve(days, costs, i, dp);
        
        return dp[idx] = min({op1, op2,op3});
            
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        
        vector<int> dp(n+1, -1);
        
        return solve(days, costs, 0, dp);
    }
};