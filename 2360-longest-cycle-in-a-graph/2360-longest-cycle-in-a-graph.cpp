class Solution {
public:
    
    void dfs(vector<int>&edges,vector<int>&vi,vector<int>&extra,vector<int>&distance,int &node,int& ans,int d){
        
        if(node != -1){
            
            if(!vi[node]){
                
                vi[node] =1;
                extra[node] =1;
                distance[node] = d;
                
                dfs(edges,vi,extra,distance,edges[node],ans,d+1);
                
            }
            else if(extra[node])
                ans = max(ans,d - distance[node]);        
                
            extra[node] =0;
        }
        
    }
    int longestCycle(vector<int>& edges) {
    
        int size = edges.size();
        vector<int>vi(size);
        vector<int>extra(size);
        vector<int>distance(size);
        
        int ans =-1;
        for(int i=0; i<edges.size();i++)
            if(!vi[i]) dfs(edges,vi,extra,distance,i,ans,0);
        
        return ans;
        
    
    }
};