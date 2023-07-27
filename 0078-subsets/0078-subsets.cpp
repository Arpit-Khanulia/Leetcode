class Solution {
public:
    
    void find(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>ds){
        
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        find(i+1,nums,ans,ds);
        
        
        ds.push_back(nums[i]);
        find(i+1,nums,ans,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,nums,ans,ds);
        return ans;
    }
};