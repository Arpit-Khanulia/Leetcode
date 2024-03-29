class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        k = k% len(nums)
        nums[:] = nums[-(k+1)::-1] + nums[-1:-(k+1):-1]
        nums[:] = nums[::-1]
        