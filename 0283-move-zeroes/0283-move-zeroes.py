class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        size = len(nums)
        i = 0
        j = 0
        
        while j<size:
            
            while j< size and nums[j] == 0:
                j+=1
                
            if j == size:
                break
            
            nums[i], nums[j] = nums[j], nums[i]
            i+=1
            j+=1
        