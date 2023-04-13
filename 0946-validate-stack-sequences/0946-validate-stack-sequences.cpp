class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        
        stack<int>s;
        int j =0;
        
        for(int i=0; i<pushed.size();i++){
            
            s.push(pushed[i]);
            
            while(!s.empty() and s.top() == popped[j]){
                j++;
                s.pop();
                
            }
        }
        
        if(s.empty() == 1) return 1;
        return 0;
        
    }
};