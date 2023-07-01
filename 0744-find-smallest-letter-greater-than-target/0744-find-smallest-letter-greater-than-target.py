class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        
        low = 0
        high = len(letters)-1
        if target >= letters[len(letters)-1]: return letters[0]
        
        while(low <= high):
            
            mid = (low + high)//2
            if letters[mid] > target: high = mid-1
            else : low = mid +1
                    
        return letters[low]
        