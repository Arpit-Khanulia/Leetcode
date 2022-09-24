class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int maxi =0;
        unordered_set<int>s;
        
        for(int i =0;i<nums.size();i++)
            s.insert(nums[i]);
        
        for(auto &i : s){
            if(!s.count(i-1))
            {
                int count =1;
                int no = i+1;
                while(s.count(no))
                {
                    count ++;
                    no++;
                }
                
                maxi = max(maxi,count); 
                
            }
            
                
        }
        
        return maxi;
    }
};