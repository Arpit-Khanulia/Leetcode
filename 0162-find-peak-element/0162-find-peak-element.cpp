class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        int s = 0;
        int e = nums.size();
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(mid >0 and mid < n-1){
                
                if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) return mid;
                else if( nums[mid] < nums[mid+1]) s = mid+1;
                else e = mid-1;
            }
               
            else if(mid == 0 and mid+1<n ){
                
                if(nums[mid] > nums[mid+1]) return mid;
                else s = mid+1;
            }
            else if(mid == n-1 and mid>0 ) {
                
                if(nums[mid] > nums[mid-1]) return mid;
                else e = mid-1;
            }
        }
        
        
        return -1;
    }
};