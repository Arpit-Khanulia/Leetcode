class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int,vector<int>>m;
        
        for(int i=0; i<n;i++){
            
            m[arr[i]].push_back(i);
            
        }
        
        
        queue<pair<int,int>>q;
        q.push({0,0});
       
        vector<int>vi(n,0);
        vi[0]=1;
        
        while(!q.empty()){
            
            int index = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            cout<<index<<" ";
            
            
            if(index == n-1) return steps;
            
            if(index-1 >=0 and !vi[index-1]){
                
                q.push({index-1,steps+1});
                vi[index] =1;
            }
            
            if(index+1 < n and !vi[index+1]){
                
                q.push({index+1,steps+1});
                vi[index] =1;
            }
            
            for(auto i: m[arr[index]]){
                
                if(!vi[i]){
                    
                    q.push({i,steps+1});
                    vi[i]=1;
                }
            }
            
            m.erase(arr[index]);
            
        }
        
        return -1;
    }
};