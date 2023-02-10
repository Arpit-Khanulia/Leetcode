class Solution {
public:
    
    bool find(vector<int>&vi,vector<int>&extra,vector<vector<int>>&graph,vector<int>&ds,int node){
        
        vi[node] =1;
        extra[node] =1;
        
        for(auto i: graph[node]){
            
            if(!vi[i])
            {
                if(find(vi,extra,graph,ds,i) == 0) return 0;
            }
            else if(extra[i]) return 0;
            
            
        }
        
        extra[node] =0;
        ds[node] =1;
        return 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int>vi(n);
        vector<int>ds(n);
        vector<int>extra(n);
        
        vector<int>ans;
        for(int i=0; i< n; i++){
            
            if(!vi[i]) find(vi,extra,graph,ds,i);
        }
        
        
        for(int i=0; i<n;i++)
            if(ds[i] == 1) ans.push_back(i);
        
        return ans;
        
    }
};