class Solution {
public:
    
    set<string>s;
    
    bool check(string words){
        
        for(int i=0; i<words.size();i++){
            
            string prefix = words.substr(0,i);
            string suffix = words.substr(i,words.size()-1);
            
            if(s.find(prefix) != s.end() && (s.find(suffix) != s.end() || check(suffix)))
                return true;
        }
        
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto i: words)
            s.insert(i);
        
        vector<string>ans;
        
        for(auto i: words){
            
            if(check(i)) ans.push_back(i);
        }
        
        return ans;
    }
};