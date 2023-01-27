class Solution {
public:
    
    void find(vector<int>&ds, vector<vector<int>>&ans,int &k, int &n,int no){
        
        if(no>n+1) return ;
        
        if(ds.size() == k){
            ans.push_back(ds);
            return ;
        }
        
        ds.push_back(no);
        find(ds,ans,k,n,no+1);
        
        ds.pop_back();
        find(ds,ans,k,n,no+1);
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>ds;
        vector<vector<int>>ans;
        
        find(ds,ans,k,n,1);
        
        return ans;
        
    }
};