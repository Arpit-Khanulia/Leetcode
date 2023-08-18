class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        sort(intervals.begin(),intervals.end());
        int low = intervals[0][0];
        int high = intervals[0][1];
        
        
        vector<vector<int>>ans;
        for(int i=1 ;i<intervals.size();i++){
            
            
            if(high < intervals[i][0]){
                
                ans.push_back({low,high});
                
                low = intervals[i][0];
                high = intervals[i][1];
            }
            else {
                
                high = max(high,intervals[i][1]);
            }
        }
        
        ans.push_back({low,high});
        
        return ans;
        
    }
};