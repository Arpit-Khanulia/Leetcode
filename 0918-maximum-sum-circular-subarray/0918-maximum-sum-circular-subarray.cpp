class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int msum =0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        int totalsum =0;
        
        for(int i =0; i<nums.size();i++){
            
            sum = sum + nums[i];
            msum = msum + nums[i];
            
            maxsum = max(sum,maxsum);
            minsum = min(msum,minsum);
            
            if(sum <0) sum =0;
            if(msum > 0) msum =0;
            
            totalsum = totalsum + nums[i];
            
        }
        cout<<maxsum<<" "<<minsum<<endl;
        if(maxsum < 0) return maxsum;
        
        return max(maxsum, totalsum - minsum);
        
    }
};