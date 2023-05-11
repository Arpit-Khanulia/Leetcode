class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        
        vector<int>ans;
        
        int i=0;
        int j=0;
        int size = nums.size();
        while(i<size and j<size){
            
            while(i<size and nums[i]<0) i++;
            
            while(j<size and nums[j]>0) j++;
            
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            
            i++;
            j++;
        }
        
        return ans;
    }
};