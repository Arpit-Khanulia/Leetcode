class Solution {
public:
    int trap(vector<int>& height) {
        
        
        int ans =0;
        int size =height.size();
                         
        vector<int>maxleft(size);
        vector<int>maxright(size);
        
        maxleft[0] = height[0];
        maxright[size-1] = height[size-1];
        
        for(int i=1; i<size;i++) maxleft[i] = max(maxleft[i-1],height[i]);
        for(int j=size-2; j>=0; j--) maxright[j] = max(maxright[j+1],height[j]);

        
        for(int i=0; i<size;i++)
            ans += min(maxleft[i],maxright[i]) - height[i];
        
        return ans;
        
    }
};



