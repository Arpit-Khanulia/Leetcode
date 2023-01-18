class Solution {
public:
    
    int find(int a, vector<int>&parent){
        
        if(a == parent[a]) return a;
        
        return parent[a] = find(parent[a],parent);
        
    }
    
    void unionn(int a, int b,vector<int>&parent){
        
        int x = find(a,parent);
        int y = find(b,parent);
        
        if(x == y) return ;
        
        if(x<y) parent[x] = y;
        else parent[y] = x;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();
        vector<int>adj[size];
        vector<int>parent(size);
        
        for(int i=0; i<size; i++)
            parent[i] =i;
        
        for(int i =0; i<size; i++){
            for(int j =0; j<size; j++){
                
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        
        for(int i=0; i<size;i++)
        for(auto j: adj[i]){
            
            unionn(i,j,parent);
            
        }
        
        set<int>leader;
        for(int i=0; i<size; i++)
            leader.insert(find(i,parent));
        
        
        return leader.size();
        
    }
};