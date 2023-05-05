class Solution {
public:
    int maxVowels(string s, int k) {
        
        int i =0;
        int j =0;
        int count =0;
        int maxi =0;
        
        while(j<s.size()){
            
            
            if(s[j] == 'a' ||s[j] == 'e' ||s[j] == 'i' ||s[j] == 'o' ||s[j] == 'u')
            {
                count++;
            }
            

            
            j++;
            
            if(j-i>k)
            {
                
                if(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u')
                    count--;
                i++;
            }

            if(j-i == k){
                
                maxi = max(maxi,count);
            }
            
            
                   
        }
        
        return maxi;
        
    }
};