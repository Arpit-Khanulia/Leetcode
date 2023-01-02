class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int flag =1;
        
        if(word[0] >='A' && word[0]<= 'Z')
        {
            
            //first capital
            if(word[1] >='a' && word[1] <= 'z')
            {
                for(int i =1; i<word.size();i++)
                {
                    if(!(word[i] >= 'a' && word[i] <='z'))
                        flag =0;
                }
                
            }
            
            else{
                
                //all capital

                for(int i=0; i<word.size();i++)
                {
                    if(!(word[i]>='A' && word[i]<='Z'))
                        flag = 0;

                }   
                
            } 
            
        }
        
        else{
            
            //all small
            
            for(int i=0;i<word.size();i++)
            {
                if(!(word[i]>='a' && word[i]<='z'))
                    flag = 0;
            }
        }
        
    return flag;
        
    }
};