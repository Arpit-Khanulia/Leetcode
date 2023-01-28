class Solution {
public:
    
    int find(vector<int>nums,int i, vector<int>&dp){
        
        
        if(i >= nums.size()) return 0;
        
        if(dp[i] != -1 ) return dp[i];
        
        int add = nums[i] + find(nums,i+2,dp);
        int notadd = find(nums,i+1,dp);
        
        return dp[i] = max(add,notadd);
        
    }
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size()+1,-1);
        return find(nums,0,dp);
    }
};