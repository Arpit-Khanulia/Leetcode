class SummaryRanges {
    
    int check[10000] ={0};
    map<int,int>m;
    
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        
        check[value] =1;
        
        int start = value;
        int end = value;
        while( start >0 && check[start-1] == 1){
            
            start--;
            m.erase(start);
            
        }
        
        while(end<10000 && check[end+1] == 1){
            
            end++;
            m.erase(end);
            
        }
        
        m[start] = end;
        
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>>ans;
        
        for(auto i: m)
            ans.push_back({i.first,i.second});
        
        
        return ans;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */