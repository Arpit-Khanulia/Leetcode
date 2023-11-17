class Solution {
public:
    
    void generate(int open ,int close, string & ds, vector<string>&ans){
        
        
        if(open == 0 and  close == 0){
            
            ans.push_back(ds);
            return;
        }
        
        if(open>0){
            
            ds.push_back('(');
            generate(open-1,close,ds,ans);
            ds.pop_back();          
        }

        if(close>open){
            
            ds.push_back(')');
            generate(open,close-1,ds,ans);
            ds.pop_back();
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        string ds;
        vector<string>ans;
        generate(n,n,ds,ans);
        return ans;
    }
};