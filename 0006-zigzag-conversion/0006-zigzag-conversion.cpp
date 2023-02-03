class Solution {
public:
    string convert(string s, int numRows) {
        
        int n = s.size();
        
        if(numRows == 1) return s;
        vector<string>temp(numRows);
        int j=0; 
        int d=1;
        for(int i=0; i<n;i++){
            
            temp[j].push_back(s[i]);
            
            if(j == numRows-1) d = -1;
            if(j == 0) d = 1;
            
            j = j + d;
            
        }
        
        string ans;
        
        for(auto i : temp)
            for(auto j : i)
                ans.push_back(j);
        
        return ans;
        
    }
};