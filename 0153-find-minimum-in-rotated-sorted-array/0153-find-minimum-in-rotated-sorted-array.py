class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        size = len(nums)
        start = 0
        high = size-1
        
        if size ==1 : return nums[0]
        while start <= high:
            
            mid= (start + high) //2
            
            nextelement = (mid +1)%size
            prevelement = (mid-1+size)%size
            
            if nums[mid] < nums[prevelement] and nums[mid] < nums[nextelement]: return nums[mid]
            elif nums[mid] < nums[-1]: high = mid-1
            else: start = mid +1
            
        return -1
        