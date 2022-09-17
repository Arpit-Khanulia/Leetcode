class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        
        find(candidates,target,ans,ds,0);
        
        return ans;
        
    }
    
    void find(vector<int>&a,int target,vector<vector<int>>&ans,vector<int>ds,int i){
        
        if(i == a.size()){
            
            if(target == 0)
                ans.push_back(ds);
            
            return;
        }
        
        if(a[i]>target)
            find(a,target,ans,ds,i+1);
        
        else{
        
            ds.push_back(a[i]);
            find(a,target-a[i],ans,ds,i+1);
        
             while(i+1<a.size()  &&  a[i] == a[i+1])
                i++;
        
             ds.pop_back();
             find(a,target,ans,ds,i+1);
            
        }
    }
};