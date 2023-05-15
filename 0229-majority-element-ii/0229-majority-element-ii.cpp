class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        
        for(int i =0;  i<nums.size(); i++){
            
            if(count1 ==0 and nums[i]!= el2){
                
                count1 =1;
                el1 = nums[i];
            }
            else if(count2 == 0 and nums[i] != el1){
                count2 =1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) count1++;
            else if(nums[i] == el2) count2++;
            else{
                count1--;
                count2--;
            }
            
        }
        
        vector<int>ans;
        count1 =0;
        count2 =0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == el1) count1++;
            else if(nums[i] == el2) count2++;
        }
        
        int n = nums.size() /3;
        if(count1 > n) ans.push_back(el1);
        if(count2 > n) ans.push_back(el2);
        
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};