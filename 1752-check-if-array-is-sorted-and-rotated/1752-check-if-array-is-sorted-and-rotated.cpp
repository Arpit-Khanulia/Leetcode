class Solution {
public:
    bool check(vector<int>& nums) {
        
        int i =0;
        int flag = 0;
        int size = nums.size();
        for(i=0; i<size-1;i++){
            
            if(nums[i]>nums[i+1]) {
                
                flag = 1;
                break;
            }
        }
        
        if(flag and nums[size-1] > nums[0]) return 0;
        
        for(int j = i+1; j<size-1;j++)
            if(nums[j+1] < nums[j]) return 0;
        
        return 1; 
        
    }
};