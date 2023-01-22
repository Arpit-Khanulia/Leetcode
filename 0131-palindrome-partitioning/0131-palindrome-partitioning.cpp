class Solution {
public:
    
    int ispallindrome(string s, int i, int j){
        
        while(i<=j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        
        return 1;
    }
    void find(string s,vector<vector<string>>&ans,vector<string> ds,int i){
        
        
        if(i == s.size()){
            ans.push_back(ds);
            return ;
        }
        
        for(int index = i; index<s.size();index++){
            
            if(ispallindrome(s,i,index)){
                ds.push_back(s.substr(i,index+1-i));
                find(s,ans,ds,index+1);
                ds.pop_back();
            }
            
            
        }
        
        
    }
    vector<vector<string>> partition(string s) {
        
        
        vector<vector<string>>ans;
        vector<string>ds;
        
        find(s,ans,ds,0);
        
        return ans;
        
    }
};