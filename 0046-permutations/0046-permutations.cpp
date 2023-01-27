class Solution {
public:
    
    void swap(vector<int>&nums,int i,int j){
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void find(vector<int>&nums,vector<vector<int>>&ans,int index){
        
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size();i++){
            
            swap(nums,i,index);
            find(nums,ans,index+1);
            swap(nums,i,index);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        vector<vector<int>>ans;
        find(nums,ans,0);
        return ans;
        
        
    }
};