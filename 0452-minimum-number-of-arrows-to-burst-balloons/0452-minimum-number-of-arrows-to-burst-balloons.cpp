class Solution {
    
public:
    
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),compare);

        
        int count =1;
        int end = points[0][1];
        for(int i=1; i<points.size();i++)
        {
            if(points[i][0] > end)
            {
                count++;
                end = points[i][1];
            }
        }
        
        return count;
        
    }
};