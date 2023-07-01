class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        def binarysearch(low,high):
            
            while low<=high:          
                mid = (low + high)//2
                if nums[mid] == target: return mid
                elif target < nums[mid] : high = mid -1
                else: low = mid +1
                
            return -1
                
        def minelement():
            
            low =0
            size = len(nums)
            high = size -1
            
            if size ==1: return nums[0]
            
            while low <= high:

                mid = (low+high)//2
                n = (mid +1)%size
                p = (mid -1 + size) %size
                
                
                if nums[mid] < nums[n] and nums[mid] < nums[p]: return mid
                elif nums[mid] < nums[high]: high = mid -1
                else: low = mid +1
                
            return -1
        
        mini = minelement()
        print(mini)
        a = binarysearch(0,mini-1)
        b = binarysearch(mini,len(nums)-1)
        
        if a!=-1 : return a
        else : return b
            
        