class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        d ={0:1}
        sum =0
        ans =0
        for i in range(len(nums)):
            
            sum += nums[i]
            if sum - k in d: ans += d[sum-k]
            d[sum] = d.get(sum,0) +1
            
                
        return ans