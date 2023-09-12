class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>ans;
        string temp;
        for(int i=0 ;i<s.size();i++){
            
            
            if(s[i] == ' ' and !temp.empty()){
                ans.push_back(temp);
                temp.clear();
            }
            else if(s[i]!= ' '){
                temp.push_back(s[i]);
            }
        }
        
        if(!temp.empty()) ans.push_back(temp);
        
        
        reverse(ans.begin(),ans.end());
        string finalans;
        
        for(auto i:ans){
            finalans += i;
            finalans +=' ';
        }
        
        finalans.pop_back();
        
        return finalans;
        
    }
};