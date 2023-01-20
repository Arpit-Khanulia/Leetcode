class Solution {
public:
    
    void reverse(string & s,int i, int j){
        
        while(i<=j){    
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        
        
        int i =0; 
        int j =0;
        
        while(j<s.size())
        {
            while(s[j] != ' ' && j<s.size()){
                j++;
            }
            
            reverse(s,i,j-1);
            j++;
            i = j;
            

        }
        
        return s;
    }
};