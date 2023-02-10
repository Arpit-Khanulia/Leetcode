class Solution {
public:
    
    bool solve(vector<vector<int>>adj,vector<int>&color,int start){
        
        queue<int>q;
        color[start] =0;
        q.push(start);
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto i: adj[node]){
                
                if(color[i] == -1){
                    
                    color[i] = !color[node];
                    q.push(i);
                }else{
                    
                    if(color[i] == color[node]) return false;
                    
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>adj[n]; 
        vector<int>color(n,-1);
        
        for(int i=0 ;i<n;i++){
            if(color[i] == -1) 
                if(!solve(graph,color,i)) return false;
        }
        
        return true;
        
    }
};