class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
        q = deque()
        low =0
        high =0
        ans = []
        
        while high < len(nums):
            
            while q and q[-1] < nums[high]:
                q.pop()
                
            q.append(nums[high])
            
            if high - low +1 == k:
                
                ans.append(q[0])
                
                if q[0] == nums[low]:
                    q.popleft()
                low +=1
                
                
            high+=1
            
        return ans
                
                
        