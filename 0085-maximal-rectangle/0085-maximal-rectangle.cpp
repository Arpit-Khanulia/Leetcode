int mah(vector<int> heights) {
        

        stack<pair<int,int>>sl;
        vector<int>leftsmaller;

        for(int i=0; i<heights.size();i++){
            
            while(sl.size()>0 and sl.top().first >= heights[i]) sl.pop();
            if(sl.empty()) leftsmaller.push_back(-1);
            else if(sl.top().first < heights[i]) leftsmaller.push_back(sl.top().second);
            
            sl.push({heights[i],i});

        }

        stack<pair<int,int>>sr;
        vector<int>rightsmaller;
        for(int i=heights.size()-1;i>=0;i--){

            while(sr.size()>0 and sr.top().first >= heights[i]) sr.pop();
            if(sr.empty()) rightsmaller.push_back(heights.size());
            else if(sr.top().first < heights[i]) rightsmaller.push_back(sr.top().second);
            
            sr.push({heights[i],i});

        }

        reverse(rightsmaller.begin(),rightsmaller.end());
        
        int maxi =0;

        for(int i=0; i<heights.size();i++)
        maxi = max(maxi, heights[i]*(rightsmaller[i] - leftsmaller[i]-1));


        return maxi;
    }

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        vector<int>temp(col);
        for(int i=0; i<col;i++) temp[i] = matrix[0][i] - '0';

        int maxi = 0; 
        maxi = max(maxi,mah(temp));

        
        for(int i=1; i<row; i++){
                     
            for(int j =0; j<col;j++){
                
                if(matrix[i][j] - '0' ==0) temp[j] =0;
                else temp[j] = int(matrix[i][j] - '0') + temp[j]; 
            }
            
            maxi = max(maxi,mah(temp));
            
        }
        
        return maxi;
        
    }
};