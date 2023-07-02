class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        def firstoccurrence():
            low = 0
            high = len(nums)-1
            res = -1
            while low <= high:

                mid = (low + high)//2

                if target < nums[mid]: high = mid -1
                elif target > nums[mid]: low = mid +1
                else:
                    res = mid
                    high = mid -1

            return res
    
        def lastoccurrence():
            low = 0
            high = len(nums)-1
            res = -1
            while low <= high:

                mid = (low + high)//2
                

                if target < nums[mid]: high = mid -1
                elif target > nums[mid]: low = mid +1
                else:
                    res = mid
                    low = mid +1

            return res
            
        return [firstoccurrence(),lastoccurrence()]