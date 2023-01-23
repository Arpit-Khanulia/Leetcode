class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>adj[n+1];
        
        for(auto i: trust)
        {
            adj[i[0]].push_back(i[1]);
        }
            
        int judge =0;
        for(int i=1; i<=n;i++)
            if(adj[i].empty()) judge = i;
        
        if(judge == 0) return -1;
        
        for(int i=1; i<=n;i++){
            int flag =0;
            for(auto j: adj[i])
                if(j== judge)flag=1;
            if(flag==0 && i != judge) return-1;
        }
        
        return judge;

    }
};