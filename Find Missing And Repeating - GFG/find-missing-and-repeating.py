#User function Template for python3

class Solution:
    def findTwoElement( self,arr, n): 
        # code here
        
        sumarr =0
        sumsq = 0
        for i in arr: 
            sumarr += i
            sumsq += i*i
        
        sumno = n*(n+1)//2
        squareno = n*(n+1)*(2*n+1)//6
        
        a = sumno - sumarr
        b = squareno - sumsq
        
        b = b//a
        missing = (a + b)//2
        repeat = missing - a
        
        return [repeat,missing]
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

    tc=int(input())
    while tc > 0:
        n=int(input())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.findTwoElement(arr, n)
        print(str(ans[0])+" "+str(ans[1]))
        tc=tc-1
# } Driver Code Ends