class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int prev = INT_MIN;
        for(int i=0; i<nums.size();i++){
            
            if(nums[i] == prev) continue;
            prev = nums[i];
            
            int left = i+1;
            int right = nums.size()-1;
            
            int n = -1 * nums[i];
            
            while(left< right){
                
                int sum = nums[left] + nums[right];
                if(sum == n){
                    ans.push_back({nums[left],nums[right],nums[i]});
                    left++;
                    right--;
                    while(left < right and nums[left-1] == nums[left]) left++;
                    while(left < right and nums[right+1] == nums[right]) right--;
                } 
                
                if(sum < n) left++;
                else if(sum>n) right--;
                    
            }
            
        }
        
        return ans;
    }
};