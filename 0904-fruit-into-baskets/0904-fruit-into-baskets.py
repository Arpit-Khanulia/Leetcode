class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        
        low =0
        high =0
        
        maxi =0
        dic ={}
        
        ans =0
        
        
        while high < len(fruits):
            
            dic[fruits[high]] = dic.get(fruits[high],0) +1
            
            if len(dic) > 2:
                
                while len(dic) >2:
                    
                    dic[fruits[low]] -=1
                    if dic[fruits[low]] == 0: dic.pop(fruits[low])
                    low +=1
                
            if len(dic) == 2:
                maxi = max(maxi,high -low +1)
                ans = ans + 1
                
            high +=1;
            
        if len(dic) < 2:
            maxi = dic[fruits[0]]
            
        return maxi