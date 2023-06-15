class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        count = 0
        
        for i in range(len(nums)):
            
            if count == 0 : m = nums[i]
                
            if nums[i] == m: count +=1
            else: count-=1
            
        return m
        