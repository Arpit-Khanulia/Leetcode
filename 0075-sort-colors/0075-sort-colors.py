class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # ooooooo11111*******2222222
        # 00000 L 111111 M-----H 2222222
        #       1        *     *
        
        l =0
        m =0
        h =len(nums)-1
        
        while m<=h:
            
            if nums[m] == 0: 
                nums[l],nums[m] = nums[m],nums[l]
                m+=1
                l+=1
            elif nums[m] ==1: m+=1
            else:
                nums[m],nums[h] = nums[h],nums[m]
                h-=1
                
                