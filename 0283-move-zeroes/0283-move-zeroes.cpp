class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        vector<int>ans(size);
        
        int i =0;
        int k =0;
        int j =size-1;
        while(i< size){
            
            if(nums[i] == 0)
            {
                ans[j] = 0;
                j--;
                
            }
            else{
                ans[k] = nums[i];
                k++;
            }
            
            i++;
            
        }
        
        nums = ans;
        
    }
};