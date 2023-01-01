class Solution {
public:
    bool wordPattern(string pattern, string s) {

        map<char,string>m;
        map<string,char>m2;
        vector<string>s1;
        string temp;

        for(int i =0; i<s.size();i++)
        {
            
            if(s[i] ==' ')
            {
                s1.push_back(temp);
                temp.clear();
            }
            else temp.push_back(s[i]);
            
        }
        s1.push_back(temp);

        if(s1.size() != pattern.size())
        {
            cout<<s1.size()<<" "<<pattern.size()<<endl;

            return 0;
        } 
        
        int flag = 1;

        for(int i=0; i<s1.size();i++)
        {
            if(m.find(pattern[i]) != m.end())
            {
                if(  m[pattern[i]] != s1[i]  )
                {
                    flag = 0;
                    break;
                } 
                    
                continue;
            }
            else{
                m[pattern[i]] = s1[i];
            }
        }


        for(int i=0;i<s1.size();i++)
        {
            if(m2.find(s1[i]) != m2.end())
            {
                if(m2[s1[i]]  != pattern[i])
                {
                    flag =0;
                    break;

                }
                continue;
            }
            else {
                m2[s1[i]] = pattern[i];
            }
        }



        return flag;
        
    }
};