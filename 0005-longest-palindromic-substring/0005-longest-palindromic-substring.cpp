class Solution {
public:
    string longestPalindrome(string s) {
        
        
        string maxi="";
        

        
        for(int i=0; i<s.size();i++){
            
             // odd
            
            int left = i;
            int right = i;
            string temp ="";
            while(left>=0 and right<= s.size()-1 and s[left] == s[right]){


                temp = s.substr(left,right-left+1);
                if(temp.size() > maxi.size()){

                    maxi = temp;
                    cout<<maxi<<endl;
                }
                
                left--;
                right++;

            }
            
            left = i;
            right = i+1;
            
            while(left>=0 and right<= s.size()-1 and s[left] == s[right]){


                temp = s.substr(left,right-left+1);
                if(temp.size() > maxi.size()){

                    maxi = temp;
                }
                
                left--;
                right++;

            }

            
        }
        
        
        return maxi;
        
    }
};