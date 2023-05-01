class Solution {
public:
    double average(vector<int>& salary) {
        
        double sum =0;
        int min = INT_MAX;
        int max = INT_MIN;
        double ans = 0;
        
        for(auto i: salary){
            
            if(i<min) min = i;
            if(i>max) max = i;
            
            sum = sum + i;
        }
        
        ans = (sum-min-max)/(salary.size()-2);
        
        return ans;
    }
};