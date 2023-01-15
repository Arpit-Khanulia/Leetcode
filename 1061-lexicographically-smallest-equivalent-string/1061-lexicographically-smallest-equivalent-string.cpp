class Solution {
public:
    
    int find(char a,string &parent){
        
        if(parent[a - 'a'] == a) return a;
        
        else
        {
            char b =find(parent[a -'a'],parent);
            parent[a - 'a'] = b;
            return b;
            
        }
            
         
    }
        
    void unionn(char a, char b,string & parent){
        
        char arep = find(a,parent);
        char brep = find(b,parent);
        
        if(arep == brep) return ;
        
        if(brep<arep) parent[arep - 'a'] = brep;
        
        else if(arep<brep) parent[brep - 'a'] = arep;
            
       
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        string parent;
        
        for(int i =0; i<26; i++)
            parent.push_back('a' +i);
               
        for(int i =0;i<s1.size();i++)
        {
            unionn(s1[i],s2[i],parent);
        }
        
        
        string ans;
        
        for(int i =0; i<baseStr.size();i++){
            
            char a = find(baseStr[i],parent);
            ans.push_back(a);
        }
        
        return ans;
        
    }
};