class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // O(n3) solution
        
//         int sum =0;
//         int maxi = nums[0];
//         for(int i = 0;i<nums.size();i++)
//         {
//             for(int j =0;j<nums.size();j++)
//             {
//                 for(int k =i; k<=j;k++)
//                     sum = sum + nums[k];
                
//                 maxi = max(maxi,sum);
//                 sum =0;
//             }
//         }
        
//         return maxi;
        
        
        // O(N2) approach
        
//         int sum =0;
//         int maxi = nums[0];
//         for(int i = 0;i<nums.size();i++)
//         {   int sum =0 ;
//             for(int j =i;j<nums.size();j++)
//             {
//                 sum = sum + nums[j];
//                 maxi = max(maxi,sum);
//             }
//         }
        
//         return maxi;
        
        // O(N) solution
        
        int sum =0;
        int maxi =nums[0];
        for(int  i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            maxi = max(maxi,sum);
            
            if(sum <0) sum =0;
        }
        
        return maxi;
    
    }
};