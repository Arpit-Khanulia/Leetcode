class Solution {
public:
    
    void solve(string digits, int j, map<char,string>&m, vector<string>&ans,string &ds){
        
        
        if(j == digits.size()) {
            ans.push_back(ds);
            return;
        }
        
        string s = m[digits[j]];
        
        for(int i=0; i<s.size();i++){
            
            ds.push_back(s[i]);
            solve(digits,j+1,m,ans,ds);
            ds.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        
        if(digits == "") return {};
        map<char,string>m = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
        
        vector<string>ans;
        string ds ="";
        solve(digits, 0, m,ans,ds);
        
        return ans;
        
    }
};