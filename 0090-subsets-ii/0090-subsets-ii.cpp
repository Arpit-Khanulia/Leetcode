class Solution {
public:
    
    void find(vector<vector<int>>&ans,vector<int>&ds,vector<int> nums, int  i){
        
        
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        find(ans,ds,nums,i+1);
        ds.pop_back();
        
        if(i< nums.size()-1){
            
            while(i+1 < nums.size() and nums[i] == nums[i+1]){
                i++;
            }
        }
        
        find(ans,ds,nums,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        find(ans,ds,nums,0);
        return ans;
        
    }
};