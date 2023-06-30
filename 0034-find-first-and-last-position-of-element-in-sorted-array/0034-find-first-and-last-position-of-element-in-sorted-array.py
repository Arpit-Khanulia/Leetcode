class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        def search(target):
            
            low = 0
            high = len(nums)-1
            
            while low <= high:

                mid = (low + high)//2

                if target > nums[mid]:
                    low = mid+1
                    
                else : high = mid-1     
                
            return low
        
        lo = search(target)
        high = search(target +1)-1
        
        if lo<=high :return [lo,high]
        
        return [-1,-1]
        