#Your task is to complete this function
#Your should return the required output
class Solution:
    def maxLen(self, n, arr):
        #Code here
        
        d = {0:-1}
        sum =0
        maxi =0
        for i in range(len(arr)):
            
            sum += arr[i]
            
            if(sum in d): maxi = max(maxi,i-d[sum])
            
            if not sum in d:d[sum] = i
            
        return maxi
            



#{ 
 # Driver Code Starts
if __name__=='__main__':
    t= int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.maxLen(n ,arr))
# Contributed by: Harshit Sidhwa
# } Driver Code Ends