class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        
        int ans;
        int sum = nums[0];
        if(nums.size() ==  1) return sum;
        
        for(int i=1; i< nums.size();i++){
            
            if(nums[i] > nums[i-1]) sum = sum+nums[i];
            else {
                ans = max(sum,ans);
                sum = nums[i];
            }
        }
        
        return max(ans,sum);
        
    }
};