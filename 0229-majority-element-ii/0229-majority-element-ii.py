class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        
        count1 =0
        count2 =0
        
        el1 = float(-inf)
        el2 = float(-inf)
        
        
        for i in nums:
            
            if count1 ==0 and el2 != i:
                el1 = i
                count1+=1
            
            elif count2 == 0 and el1 != i: 
                el2 = i
                count2+=1
            
            elif i == el1: count1+=1
            
            elif i== el2: count2+=1
                
            else: 
                count1-=1
                count2-=1
                
        ans =[]
        
        count1 =0
        count2 =0
        
        for i in nums:
            if el1 == i: count1+=1
            if el2 == i: count2+=1
                
        
        if count1 >= len(nums)//3+1: ans.append(el1)
        if count2 >= len(nums)//3+1: ans.append(el2)
            
        return ans
        