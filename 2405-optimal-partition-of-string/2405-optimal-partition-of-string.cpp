class Solution {
public:
    int partitionString(string s) {
        
        int count =1;
        set<char>st;
        
        for(int i=0; i<s.size();i++){
            
            if(st.find(s[i]) != st.end()){
                
                count++;
                st.clear();
                st.insert(s[i]);
            }
            else{
                
                st.insert(s[i]);
            }
        }
        
        return count;
        
    }
};