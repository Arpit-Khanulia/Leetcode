class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        i =0
        j =0
        
        while j< len(nums):
            
            while(j < len(nums) and nums[j] == nums[i]):
                j +=1
                
            i +=1
            
            if(i< len(nums) and j< len(nums)):
                nums[i] = nums[j]
            
        return i
        