class Solution {
public:
    
    void find(string s, vector<string>&ans,string ds, int index){
        
        if(ds.size() == s.size()){
            
            ans.push_back(ds);
            return;
        }
        
        if(s[index] >= '0' && s[index]<= '9') {
            
            ds.push_back(s[index]);
            find(s,ans,ds,index+1);
        }
        
        else{
            
            ds.push_back(s[index]);
            find(s,ans,ds,index+1);
            
            ds.pop_back();
            
            ds.push_back(toupper(s[index]));
            find(s,ans,ds,index+1);
                
        }
        

        
        
    }
    vector<string> letterCasePermutation(string s) {
        
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        
        vector<string>ans;
        string ds;
        
        find(s,ans,ds,0);
        
        return ans;
            
        
    }
};