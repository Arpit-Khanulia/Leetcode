class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        map<char,int>m;

        for(int i=0; i<order.size();i++) m[order[i]] = i;

        for(int i=0; i<words.size()-1;i++){

            int a = 0,b=0;

            while(a< words[i].size()  && b<words[i+1].size()){
                if(m[words[i][a]] < m[words[i+1][b]]) break;
                if(m[words[i][a]] > m[words[i+1][b]]) return 0;
                a++;
                b++;
                if(words[i][a] && !words[i+1][b]) return 0;
            }
        }

        return 1;
        
    }
};