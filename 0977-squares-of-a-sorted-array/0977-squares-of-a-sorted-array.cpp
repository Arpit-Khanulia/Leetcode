class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int size = nums.size();
        vector<int>ans(size);
        
        int i = 0;
        int j = size -1;
        int k = size -1;
        while(i<=j){
            
            if(abs(nums[i]) > abs(nums[j]) ){
                ans[k] = nums[i] * nums[i];
                i++;
            }
            else {
                ans[k] = nums[j] * nums[j];
                j--;
            }
            
            k--;
        }
        
        return ans;
        
    }
};