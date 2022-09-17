class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        subset(nums,ans,ds,0);
        return ans;
        
    }
    
    void subset(vector<int>nums,vector<vector<int>>&ans,vector<int>&ds,int i){
        
        if(i == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        subset(nums,ans,ds,i+1);
        ds.pop_back();
        
        while(i+1<nums.size() && nums[i] == nums[i+1])
            i++;

        subset(nums,ans,ds,i+1);

    }
};