class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        set<int>a(nums1.begin(),nums1.end());
        set<int>b(nums2.begin(),nums2.end());
        
        vector<int>one;
        vector<int>two;
        
        for(int i: a) if(b.find(i) == b.end()) one.push_back(i);
        for(int i: b) if(a.find(i) == a.end()) two.push_back(i);
        
        return {one,two};

    }
};