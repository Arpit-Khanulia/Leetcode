class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int size = numbers.size();
        int i =0; int j =size -1;
        
        while(i<=j){
            
            int sum = numbers[i] + numbers[j];
            
            if(sum == target) return {i+1,j+1};
            if(sum > target) j--;
            else i++;
        }
        return {};
        
    }
};