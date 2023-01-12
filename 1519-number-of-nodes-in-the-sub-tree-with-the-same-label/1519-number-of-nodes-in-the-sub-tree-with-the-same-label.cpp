class Solution {
public:
    
    map<char,int>dfs(vector<int>adj[],string &labels,vector<int>&ans,int node,int parent){
        
        map<char,int>m;
        m[labels[node]]++;
        
        for(int i : adj[node]){
            
            if(i!= parent)
            {   
                map<char,int>ml =dfs(adj,labels,ans,i,node);

                for(auto k: ml){

                    m[k.first] += k.second;
                }
                
            }
            

        }
        
        ans[node] = m[labels[node]];
        
        return m;
        
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int>adj[n];
        for(int i =0; i<edges.size();i++){
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>ans(n);
        
        dfs(adj,labels,ans,0,0);
        return ans;
        
        
    }
};