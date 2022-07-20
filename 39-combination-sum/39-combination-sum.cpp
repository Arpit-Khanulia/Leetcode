class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        comsum(ans,ds,candidates,target,0,0);
        
        return ans;
        
    }
    
    void comsum(vector<vector<int>>&ans, vector<int>&ds,vector<int>&candidates,int target,int index,int sum){
        if(sum > target)
            return ;
        if(index== candidates.size())
            return;
        
        if(sum == target){
            ans.push_back(ds);

            return;
        }
        
        ds.push_back(candidates[index]);
        comsum(ans,ds,candidates,target,index ,sum + candidates[index]);
        ds.pop_back();
        comsum(ans,ds,candidates,target,index+1,sum);
        
        
    }
};