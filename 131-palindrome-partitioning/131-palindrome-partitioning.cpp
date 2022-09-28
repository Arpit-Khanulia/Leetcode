class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<string>ds;
        vector<vector<string>>ans;
        find(0,ds,ans,s);
        return ans;
    }
    
    
    void find(int index, vector<string>ds, vector<vector<string>>&ans,string s){
        
        if(index == s.size())
        {
            ans.push_back(ds);
            return ;
        }
        
        
        for(int i=index;i<s.size();i++)
        {
            if(ispallindrome(s,index,i))
            {
                ds.push_back(s.substr(index,i-index+1));
                find(i+1,ds,ans,s);
                ds.pop_back();            
                
            }

        }
    }
    
    bool ispallindrome(string s,int start,int end){
        
        while(start<=end)
            if(s[start++] != s[end--])
                return false;
        
        return true;
    }
};
