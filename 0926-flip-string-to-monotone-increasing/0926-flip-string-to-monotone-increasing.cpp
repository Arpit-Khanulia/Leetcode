class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int i =0;
        while(i< s.size() &&  s[i] == '0')
            i++;

        int one =0;
        int zero =0;
        while(i<s.size()){
            
            if(s[i] == '0') zero++;
            else one++;
            
            if(zero > one)
                zero = one;
            
            i++;
        }
        return zero;
    
    }
};