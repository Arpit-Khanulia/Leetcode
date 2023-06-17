def generaterow(row):

    li= [1]
    if row == 1: return li
    temp =1
    for i in range(1,row-1):
        temp = temp * (row - i)
        temp = temp//i
        li.append(temp)

    li.append(1)
    return li

class Solution:
            
    def generate(self, numRows: int) -> List[List[int]]:
        ans =[]
        for i in range(1, numRows+1): ans.append(generaterow(i))
        return ans
        