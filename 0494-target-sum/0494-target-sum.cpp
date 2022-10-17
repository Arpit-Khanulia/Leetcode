class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum =0;
        for(int i : nums)
            sum = sum + i;
        
        if((sum - target)%2 !=0   || sum < target) return 0;
        
        target = (sum - target)/2;
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return find(nums.size(), nums,target,dp);
        
    }
    
    
    
    int find ( int n, vector<int>nums, int target, vector<vector<int>>&dp)
    {
        if(n ==0)
        {
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp[n][target] != -1) return dp[n][target];
        
        if(nums[n-1] <= target)
        return dp[n][target] =  find(n-1,nums,target-nums[n-1],dp) + find(n-1,nums,target,dp);
        return dp[n][target] = find(n-1,nums,target,dp);
    }
};