class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s =="")
            return 0;

        
        int maxi =1;
        for (int i = 0; i < s.size(); i++)
        {
            map<char, int> m;
            int j =i;
            int count =0;
            while (m.find(s[j]) == m.end() && j <= s.size()-1)
            {
                    m[s[j]]++;
                    count++;
                    j++;
                    
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};