class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        
        multiset<int>s;
        vector<int>ans;
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int>small;
        vector<int>large;
            
        if(size1 < size2)
        {
            small = nums1;
            large = nums2;
        }
        else {
            small = nums2;
            large = nums1;
        }
        
        for(int i : large)
            s.insert(i);
        
        for(int i:s) cout<<i<<" ";
        cout<<endl;
        
        for(int i:small)
            if(s.find(i) != s.end())
            {
                ans.push_back(i);
                auto it = s.find(i);
                s.erase(it);
                
            }
                
        
        return ans;
        
        
    }
};