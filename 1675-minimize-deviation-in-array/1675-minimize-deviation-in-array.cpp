class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int ans =INT_MAX;
        priority_queue<int>q;
        int mini = INT_MAX;
        for(int i=0; i<nums.size();i++){
            
            if(nums[i] %2 != 0)
            {
                q.push(nums[i]*2);
                mini = min(mini,nums[i] *2);
            }
            
            else{
                
                q.push(nums[i]);
                mini = min(mini,nums[i]);
            }
                
        }
        
        
        while(1){
            
            int maxi = q.top();
            q.pop();
            ans = min(ans, maxi - mini);
            
            if(maxi %2 != 0) break;
            
            mini = min(mini , maxi/2);
            q.push(maxi/2);
        }
        
        
        return ans;
        
        
    }
};


    