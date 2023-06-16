class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        
        p =0
        n =0
        li =[]
        size = len(nums)
        while p< size and n<size:
            
            while nums[p] <0: p+=1
            
            while nums[n]>0: n+=1
                
            li.append(nums[p])
            li.append(nums[n])
            p+=1
            n+=1
        return li
        