class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        
        set<int>s;
        for(int i: arr) s.insert(i);
        
        for(int i=1;i<=10000;i++){
            
            if(s.find(i) == s.end()) k--;
            if(k == 0) return i;
        }
        return -1;
            
        
    }
};