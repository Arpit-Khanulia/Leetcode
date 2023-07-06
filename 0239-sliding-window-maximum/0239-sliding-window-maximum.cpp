class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>q;
        
        int low =0;
        int high = 0;
        vector<int>ans;
            
        while(high < nums.size()){
            
            while(q.size()>0 and q.back() < nums[high]) q.pop_back();
            q.push_back(nums[high]);
            
            if(high - low +1 == k){
                ans.push_back(q.front());
                if(nums[low] == q.front()) q.pop_front();
                low++;
            }
            
            high++;
        }
        
        return ans;
        
    }
};