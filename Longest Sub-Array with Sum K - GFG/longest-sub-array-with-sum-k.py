#User function Template for python3

class Solution:
    def lenOfLongSubarr (self, arr, n, k) : 
        #Complete the function
        
        dict = {}
        maxi =0
        sum =0
        
        for i in range(len(arr)):
            
            sum += arr[i]
            
            if(not sum in dict): dict[sum] = i
            
            
            if sum == k: maxi = max(i+1,maxi)
            if sum-k in dict :
                maxi = max(i-dict[sum-k],maxi)
                
        return maxi
                
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    
    n, k = map(int , input().split())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    print(ob.lenOfLongSubarr(arr, n, k))




# } Driver Code Ends