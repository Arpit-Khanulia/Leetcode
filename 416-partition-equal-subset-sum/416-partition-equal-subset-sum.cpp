class Solution {
public:
    
    int find(vector<int>nums, int target, int n,vector<vector<int>>&dp){
        
        if(n == 0) return 0;
        if(target == 0) return 1;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        if(nums[n-1] <= target) return dp[n][target] =  find(nums,target - nums[n-1], n-1,dp) || find(nums,target,n-1,dp);
        return dp[n][target] =  find(nums, target, n-1,dp);
    }
    bool canPartition(vector<int>& nums) {
        
        
        int sum =0;
        
        for(int i =0;i<nums.size();i++)
            sum = sum + nums[i];
                             
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2 +1,-1));

        
        if(sum %2 !=0) return 0;
        else return find(nums,sum/2,nums.size(),dp);
        
        
    }
};