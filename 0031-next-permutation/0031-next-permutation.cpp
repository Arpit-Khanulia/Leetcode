class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int size = nums.size();
        int index =-1;
        for(int i=nums.size()-1;i>0; i--){
            
            if(nums[i-1] < nums[i]) {
                index = i-1;
                break;
            }
        }
        
        if(index == -1){
            
            reverse(nums.begin(),nums.end());
            return;
        }
        
        
        int index2 = index+1;
        for(int i =nums.size()-1; i>= index+1; i--){
            
            if(nums[i]> nums[index]){
                index2 = i;
                break;
            }
        }
        
        swap(nums[index],nums[index2]);
        
        reverse(nums.begin() + index+1, nums.end());
        
    }
};