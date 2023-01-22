class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<int,int>m;
        for(auto i: magazine)
            m[i]++;
        
        for(int i=0; i<ransomNote.size();i++)
            if(m.find(ransomNote[i]) != m.end() && m[ransomNote[i]] >0)
                m[ransomNote[i]]--;
            else return 0;
        
        return 1;
    }
};