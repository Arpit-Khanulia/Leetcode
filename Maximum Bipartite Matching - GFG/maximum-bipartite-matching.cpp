//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool solve(int person, vector<vector<int>>&g,vector<int>&vi,vector<int>&job){
        
        int n = g.size();
        int m = g[0].size();
        
        for(int i=0; i<m;i++){
            
            if(g[person][i] && !vi[i]){
                
                vi[i] =1;
                if(job[i] == -1 || solve(job[i],g,vi,job)){
                    job[i] = person;
                    return true;
                }
            }
        }
        
        return false;
        
        
    }
	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    
	    int n = G.size();
	    int m = G[0].size();
	    int count =0;
	    vector<int>job(m,-1);
	    
	    
	    for(int i=0; i<n;i++){
	        
	        vector<int>vi(m,0);
	        if(solve(i,G,vi,job)){
	            count++;
	        }
	    }
	    
	    return count;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends