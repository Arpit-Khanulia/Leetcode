class Solution {
public:
    
    int count(int n){
        
        int count =0;
        while(n){
            n = n&(n-1);
            count++;
        }
        
        return count;
        
    }
    vector<int> countBits(int n) {
        
        vector<int>ans;
        
        for(int i=0 ; i<=n;i++){
            
            ans.push_back(count(i));
        }
        
        return ans;
        
    }
};