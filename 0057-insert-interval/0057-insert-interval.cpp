class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        int size = intervals.size();
        int i=0;

            
            // newInterval current interval se bada he

            while( i < size && newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
                i++;
            }




            // new interval or current interval overlap kar rahe he ya fir current interval se chota he.

            while( i< size && newInterval[1] >= intervals[i][0] )
            {
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
                i++;
            }

            // new interval current interval se chota he
            
            ans.push_back(newInterval);
        
        
            // new interval to add ho gaya ab baki ke interval add kar deta hu   
        
            while(i<intervals.size()){

                ans.push_back(intervals[i]);
                i++;
            }

            return ans;

    }
};