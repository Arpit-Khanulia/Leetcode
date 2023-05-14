class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        set<int>s(nums.begin(),nums.end());
        int count = 1;
        int maxi = 1;
        int temp = INT_MIN;
        for(auto i: s){
            
            if(i == temp+1){
                count++;
                maxi = max(maxi,count);
            }
            else count =1;

            temp = i;        
        }
        
        return maxi;
        
    }
};