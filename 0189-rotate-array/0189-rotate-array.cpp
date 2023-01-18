class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
 
        
        int size = nums.size();
        int b = k%size;
        vector<int>ans(size);
        
        for(int i =0; i<size;i++){
            
            ans[b] = nums[i];
            b = (b+1)%size;
        }
        
        nums = ans;


        
    }
};