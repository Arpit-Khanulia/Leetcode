
class Solution {
public:
    
    int find(int a,vector<int>&parent){
        
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a],parent);
        
    }
    
    void unionn(int a, int b,vector<int>&parent,vector<int>&size){
        
        int x = find(a,parent);
        int y = find(b,parent);
        
        
        if (x == y) return;
        if (size[x] > size[y]) swap (x, y);
        
        size[y] += size[x];
        parent[x] = y;
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n = vals.size();
        vector<int>size(n,1);
        vector<int>parent(n);
        
        for(int i=0; i<n;i++)
            parent[i] =i;
        
        map<int,vector<int>>m;
        
        vector<int>adj[n];
        
        for(int i=0; i<edges.size();i++){
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i =0; i<vals.size();i++){
            m[vals[i]].push_back(i);
        }
        
        vector<int>active(n);
        int result = vals.size();
        
        
        for(auto i: m){
            for(int j : i.second){
                
                for(int k: adj[j]){
                    if(active[k]) unionn(k,j,parent,size);
                }
                active[j] =1;
                
            }
            
            vector<int>leader;
            
            for(int l : i.second){
                leader.push_back(find(l,parent));
            }
            
            for(int h=0; h<leader.size();h++)
                cout<<leader[h];
            cout<<endl;
            
            sort(leader.begin(),leader.end());
            
  
            int si = leader.size();
            for(int z=0; z<si;z++){
                
                int curr = leader[z];
                long long count =0;
                
                while(z<si && curr == leader[z] ) {
                    count++;
                    z++;
                }
                z--;
                
                result += (count * (count -1))/2;
                
            }
            
            
        }

        return result;
        
        
    }
};

// 0   1,2        
// 1   0
// 2   0,3,4
// 3   2
// 4   2