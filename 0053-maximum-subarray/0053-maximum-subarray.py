class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        
        sum1 =0
        maxi =float('-inf')
        
        for i in range(len(nums)):
            
            sum1 += nums[i]
            maxi = max(maxi, sum1)
            
            if(sum1 < 0): sum1 = 0
            
        return maxi
        