class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()) return 0;
        int i=0; 
        int j=0;
        
        map<char,int>m;
        map<char,int>m2;
        
        for(auto k:s1)
            m2[k]++;
        
        while(j<s2.size()){
            
            cout<<j<<endl;
            m[s2[j]]++;
            if(j-i+1  < s1.size()) j++;
            
            else if(j-i+1 == s1.size()){
                
                
                if(m2 == m) return 1;
                
                m[s2[i]]--;
                if(m[s2[i]] == 0) m.erase(s2[i]);
                
                j++;
                i++;
                
                
            }
            
        }
        
        return 0;
        
    }
};