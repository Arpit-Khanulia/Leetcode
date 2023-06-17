class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        maxi =0
        mini =prices[0]
        
        for i in range(len(prices)):
            maxi=  max(maxi,prices[i] - mini)
            mini = min(mini,prices[i])
            
        return maxi
            
            
        