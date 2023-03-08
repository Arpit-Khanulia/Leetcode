class Solution {
public:
    
    bool isvalid(vector<int>&piles, int n,int h){
        
        long long hours =0;
        for(int i: piles){
            
            if(i%n == 0) hours+=i/n;
            else hours+= (i/n) +1;
            
        }
        
        if(hours<= h) return 1;
        return 0;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = 0;
        int ans = 0;
        
        for(int i: piles) high = max(high,i);
        
        
        while(low<= high){
            int mid = (high + low)/2;
            // int mid = low + (high-mid)/2;
            if(isvalid(piles,mid,h)){
                
                ans = mid;
                high = mid -1;
            }
            else low = mid +1;
        }
        
        return ans;
        
    }
};