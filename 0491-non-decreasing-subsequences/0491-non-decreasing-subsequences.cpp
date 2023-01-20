class Solution {
public:
    
    void find(vector<int>&nums,vector<int>&ds,set<vector<int>>&ans,int i){
        
        if(i == nums.size())
         {
            if(ds.size() >=2)
            ans.insert(ds);
            return ;
         }
        
        if(ds.empty()){
            
            find(nums,ds,ans,i+1);
            ds.push_back(nums[i]);
            find(nums,ds,ans,i+1);
            ds.pop_back();
            
            return;
            
        }
        else if(nums[i] >= ds[ds.size()-1])
        {
            ds.push_back(nums[i]);
            find(nums,ds,ans,i+1);
            ds.pop_back();
            
        }
        
        find(nums,ds,ans,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int>ds;
        
        
        set<vector<int>>tempans;
        find(nums,ds,tempans,0);
        
        vector<vector<int>>ans(tempans.begin(),tempans.end());
        
        return ans;
        
    }
};