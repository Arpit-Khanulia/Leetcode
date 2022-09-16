class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        
        transform(s.begin(),s.end(),s.begin(),:: tolower);
        vector<string>ans;
        string ds;
        find(ans,ds,s,0);
        return ans;
        
    }
    
    void find(vector<string>&ans, string ds, string s, int i){
        
        if( i == s.size()){
            
            ans.push_back(ds);
            return ;
        }
        
        if(isdigit(s[i]))
        {
            ds.push_back(s[i]);
            find(ans,ds,s,i+1);
        }
        else{
            
            ds.push_back(s[i]);
            find(ans,ds,s,i+1);
            ds.pop_back();
        
        
            ds.push_back(toupper(s[i]));
            find(ans,ds,s,i+1);
            
        }
        
    }
};