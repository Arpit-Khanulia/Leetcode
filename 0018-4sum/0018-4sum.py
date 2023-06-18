class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        
        ans =[]
        nums.sort()
        
        for i in range(len(nums)-3):
            
            if i>0 and nums[i] == nums[i-1]: continue
            for j in range(i+1,len(nums)-2):
                
                if j> i+1 and nums[j] == nums[j-1]: continue
             
                left = j+1
                right = len(nums)-1
                tar = target - nums[i] - nums[j]
                
                while left < right:
                    
                    if nums[left] + nums[right] < tar: left+=1
                    elif nums[left]+ nums[right] > tar: right-=1
                    else : 
                        ans.append([nums[i],nums[j],nums[left],nums[right]])
                        
                        while left<right and nums[left] == nums[left+1]: left+=1
                        left +=1
                        while left<right and nums[right] == nums[right-1]: right-=1
                        right -=1
                        
                        
                    
        return ans
 
        