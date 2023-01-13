class Solution {
public:
    
    int dfs(int node,int parent,vector<int>adj[],string& s,int & maxi){
        
        
        int sum=0;
        multimap<int,char,greater<int>>m;
        for(auto i:adj[node]){
            
            if(i!= parent){
                int temp = dfs(i,node,adj,s,maxi);
                // m[temp] = s[i];  
                m.insert({temp,s[i]});
            }
            
        }
        
        int arr[2] = {0,0};
        int t=0;
        
        for(auto i:m){
            
            if(t == 2) break;
            
            if(i.second != s[node]){
                
                arr[t] = i.first;
                t++;
                
            }
        }
        
        sum = arr[0]+arr[1]+1;
        maxi = max(sum,maxi);
        
        return max(arr[0],arr[1])+1;
        
        
    }
    int longestPath(vector<int>& parent, string s) {
        
        int size = parent.size();
        vector<int>adj[size];
        
        
        for(int i=1;i<size;i++){
            
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        
        int maxi =0;
        
        dfs(0,0,adj,s,maxi);
        
        // for(int i=0;i<size;i++)
        // {
        //     cout<<i<<" ";
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j];
        //     }
        //     cout<<endl;
        // }
        
        
        
        return maxi;
        
    }
};