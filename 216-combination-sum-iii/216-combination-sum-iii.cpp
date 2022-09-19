class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        
        vector<int>ds;
        
        find(k,n,ans,ds,1);
        return ans;
    }
    
    void find(int k , int n, vector<vector<int>>&ans, vector<int>ds,int index){
        
        
        if(k == 0)
        {
            if(n == 0)
            ans.push_back(ds);
            return ;
        }
        
        if(n<0)
            return;
        
        
        for(int i =index; i<=9;i++){
            
            
            ds.push_back(i);
            find(k-1,n-i,ans,ds,i+1);
            ds.pop_back();
            
            
        }
        
        
    }
};