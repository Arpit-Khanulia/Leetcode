class Solution {
public:
    bool canMakeSubsequence(std::string str1, std::string str2) {
        int len = str1.length();
        int lent = str2.length();
        
        int ind2 = 0;
        int ind12 = 0;
        
        int countt = 0;
        
        for (int i = 0; i < lent; i++) {
            char c = str2[i];
            char ori = c;
            if (c == 'a') {
                c = 'z';
            } else {
                c--;
            }
            
            while (ind12 < len) {
                char p = str1[ind12];
                if (p == c || p == ori) {
                    countt++;
                    ind12++;
                    break;
                } else {
                    ind12++;
                }
            }
        }
        
        return countt == lent;
    }
};