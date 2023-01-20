class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<int>ds;
        vector<vector<int>>ans;
        int k =1;
        
        while(numRows--){
            
            vector<int>ds(k);
            ds[0] =1;
            ds[k-1] = 1;
            
            for(int j =1;j<k-1;j++){
                ds[j] = ans.back()[j-1] + ans.back()[j];
            }
            
            ans.push_back(ds);
            k++;
            
        }
        
        return ans;
        
    }
};