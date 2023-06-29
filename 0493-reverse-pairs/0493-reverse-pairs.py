count =0

def counter(a,low,mid,high):
    global count
    r = mid+1
    for i in range(low,mid+1):
        
        while r <= high and a[i] > 2* a[r]: r+=1
        count += r - (mid + 1)
        
        
def merge(a,low,mid,high):
    global count

    temp = []
    left = low
    right = mid+1    

    while left <= mid and right <= high:
        

        if a[left] <= a[right]:

            temp.append(a[left])
            left+=1

        else:
            temp.append(a[right])
            right +=1

    while left <=mid:
        temp.append(a[left])
        left+=1

    while right <=high:
        temp.append(a[right])
        right+=1

    for i in range(low,high+1):
        a[i] = temp[i-low]


def mergesort(a,low,high):

    if low >= high: return

    mid = (low + high)//2
    mergesort(a,low,mid)
    mergesort(a,mid+1,high)
    counter(a,low,mid,high)

    merge(a,low,mid,high)
    
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        global count
        mergesort(nums,0,len(nums)-1)
        ans = count
        count =0
        return ans
        