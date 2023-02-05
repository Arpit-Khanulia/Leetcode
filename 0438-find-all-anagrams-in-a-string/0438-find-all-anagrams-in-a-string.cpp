class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char,int>m1;
        map<char,int>m2;
        vector<int>ans;
        for(auto i: p) m1[i]++;
        
        int j=0;
        int i=0;
        
        while(j<s.size()){
            
            m2[s[j]]++;
            
            if(j-i+1 < p.size()) j++;
            else if(j-i+1 == p.size()){
                
                if(m1 == m2) ans.push_back(i);
                
                m2[s[i]]--;
                if(m2[s[i]] == 0) m2.erase(s[i]);
                
                i++;
                j++;
            }
        }
        
        return ans;
        
    }
};