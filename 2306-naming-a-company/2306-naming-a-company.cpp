class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        unordered_set<string>s(ideas.begin(),ideas.end());
        unordered_map<char,unordered_map<char,int>>m;
        long long int ans = 0;
        
        for(auto i: s){
            
            string str = i;
            char prev = str[0];
            
            for(char c ='a'; c<='z'; c++){
                
                str[0] = c;
                if(s.find(str) == s.end()){
                    m[prev][c]++;
                }
            }
        }
        
        for(auto i : s){
            
            string str = i;
            char prev = str[0];
            
            for(char c='a'; c<= 'z';c++){
                
                str[0] = c;
                if(s.find(str) == s.end()){
                    ans += m[c][prev];
                }
                
            }
            
        }
        
        return ans;
        
    }
};