class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int,int>m;
        
        for(int i=0; i<tasks.size();i++)
            m[tasks[i]]++;
        
        
        int count =0;
        for(auto i:m)
        {
            
            if(i.second == 1) return -1;
            
            
            count = count + i.second /3;
            i.second = i.second % 3;
            
            if(i.second <= 2 && i.second>0) count++;

            

        }
        
        return count;
        
    }
};