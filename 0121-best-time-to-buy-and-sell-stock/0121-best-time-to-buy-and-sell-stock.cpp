class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        vector<int>maxsum(size);
        
        int max = INT_MIN;
        for(int i = size-1; i>=0; i--){
            
            if(prices[i] > max)
            {
                max = prices[i];
                
            }
            maxsum[i] = max;
                
        }
        
        int ans =0;
        for(int i=0 ;i<size; i++){
            
            int cur = maxsum[i] - prices[i];
            if(cur > ans)
                ans = cur;
            
        }
        
        
        return ans;
        
        
        
    }
};