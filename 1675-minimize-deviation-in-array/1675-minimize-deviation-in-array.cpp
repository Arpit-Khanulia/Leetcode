class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int>q;
        int mini = INT_MAX;
        
        for(int i: nums){
            
            if(i %2 != 0){
                
                q.push(i*2);
                mini = min(mini, i*2);
            }
            else{
                
                q.push(i);
                mini = min(mini, i);
            }
            
        }
        
        
        int ans =INT_MAX;
        while(1){
            
            int maxi = q.top();
            q.pop();
            
            ans = min(ans, maxi -mini);
            
            if(maxi %2 != 0) break;
            
            mini  = min(mini, maxi/2);
            
            q.push(maxi/2);
        }
        
        return ans;
        
    }
};