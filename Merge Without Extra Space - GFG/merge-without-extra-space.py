#User function Template for python3

class Solution:
    
    #Function to merge the arrays.
    def merge(self,nums1,nums2,n,m):
        #code here
        
        left = len(nums1)-1
        right = 0
        
        while left >=0 and right < len(nums2):
            
            if nums1[left] > nums2[right]:
                nums1[left],nums2[right] = nums2[right], nums1[left]
                left -=1
                right +=1
            else: break
            
        nums1.sort()
        nums2.sort()
    



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n,m = map(int, input().strip().split())
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob=Solution()
        ob.merge(arr1, arr2, n, m)
        print(*arr1,end=" ")
        print(*arr2)
# } Driver Code Ends