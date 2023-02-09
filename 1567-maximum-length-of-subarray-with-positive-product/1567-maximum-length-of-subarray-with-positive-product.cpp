class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int ans =0;
        
        for(int i=0; i<nums.size();){
        
            int start = i;
            while(start< nums.size() and nums[start] == 0) start ++;
            
            int end = start;
            
            int sn = -1, en =-1;
            int count =0;
            
            while(end < nums.size() and nums[end] != 0){
                
                
                if(nums[end] < 0){
                    
                    if(sn == -1) sn = end;
                    en = end;
                    count ++;
                }
                end ++;
            }
            
            if(count %2 == 0 ) ans = max(ans,end-start);
            else{
                if(sn != -1)
                ans = max(ans,end-sn-1);
                if(en != -1)
                ans = max(ans,en - start);
            } 
            
            i = 1+end;
                
        }
        
        return ans;
        
    }
};