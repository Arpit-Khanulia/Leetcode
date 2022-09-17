class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        find(nums,ans,0);
        return ans;
        
    }
    
    void find(vector<int>nums,vector<vector<int>>&ans,int index){
        
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i<nums.size();i++ ){
            
            
            swap(i,index,nums);
            find(nums,ans,index+1);
            swap(i,index,nums);

        }
    }
    
    void swap(int i , int index,vector<int>&nums){
        
        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;
        
    }
};