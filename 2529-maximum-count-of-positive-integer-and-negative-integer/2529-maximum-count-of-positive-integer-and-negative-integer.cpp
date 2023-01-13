class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        auto result = equal_range(nums.begin(),nums.end(),0);
        
        int neg = result.first - nums.begin();
        int pos = nums.end() - result.second;
        
        return max(neg,pos);
        
    }
};