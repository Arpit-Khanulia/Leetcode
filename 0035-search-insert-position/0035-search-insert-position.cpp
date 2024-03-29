class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        
        int i= 0; 
        int j =nums.size()-1;
        int mid =0;
        
        
        
        while(i<=j){
            
            // if(target < nums[i])return i;
            mid = (i + j)/2;
            
            
            if(target == nums[mid]) return mid;
            
            // if(i == j && target > nums[i]) return i+1;
            
            
            if(target < nums[mid]) j = mid-1;
            
            if(target > nums[mid]) i = mid +1;
        }
        
        if(target> nums[mid]) return mid +1;
        else return mid;
        
    }
};