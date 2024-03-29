class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int maxi = INT_MIN;
        
        if(n <= 2) return n;
        
        for(int i=0; i<n; i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int count =0;
                for(int k =0 ; k<n;k++)
                {
                    if((points[j][1] - points[i][1])* (points[k][0] - points[i][0]) == (points[k][1] - points[i][1])* (points[j][0] - points[i][0])  ) count++;
                }
                
                maxi = max(maxi,count);
            }
        }
        
        return maxi;
        
    }
};