class Solution {
public:
    
    int binarysearch(vector<int>&nums, int target,int s ,int e){
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(nums[mid]< target) s = mid+1;
            else if( nums[mid] > target) e = mid-1;
            else return mid;
        }
        
        return -1;
    }
    
    int findmin(vector<int>&nums){
        
        int n = nums.size();
        int s= 0;
        int e = n-1;
        
        if(n == 1) return 0;
        
        while(s<=e){
            
            int mid  = s + (e-s)/2;
            
            int prev = (mid -1+n)%n;
            int next = (mid +1)%n;
            
            if(nums[mid] < nums[prev] and nums[mid] < nums[next]) return mid;
            if(nums[mid] < nums[n-1]) e = mid-1;
            else s = mid+1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int min = findmin(nums);
        int left = binarysearch(nums,target, 0,min-1);
        int right = binarysearch(nums,target,min,nums.size()-1);
        
        if(left != -1) return left;
        else if(right != -1) return right;
        else return -1;
        
        return 0;
        
    }
};