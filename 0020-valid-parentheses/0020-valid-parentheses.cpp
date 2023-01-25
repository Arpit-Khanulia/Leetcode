class Solution {
public:
    
    bool open(char i){
        
        if(i == '(' || i == '{' || i=='[') return true;
        return false;
    }
    
    bool check(char i,stack<char>s){
        
        if(i == '}') return (s.top() == '{');
        if(i == ')') return (s.top() == '(');
        if(i == ']') return (s.top() == '[');
        
        return 0;
        
    }
    bool isValid(string s) {
        
        stack<char>st;
        
        for(auto i:s){
            if(open(i)) st.push(i);
            else {
                
                if(st.empty()) return false;
                if(check(i,st)) st.pop();
                else return false;
            }
        }
        
        if(st.empty())
        return true;
        
        return false;
        

    }
};