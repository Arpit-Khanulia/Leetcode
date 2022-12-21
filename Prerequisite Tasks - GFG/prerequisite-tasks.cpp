//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    vector<int>adj[N];
	    for(auto i: prerequisites){
	        
	        adj[i.first].push_back( i.second);
	        
	    }
	    
	    vector<int>id(N);
	    vector<int>ans;
	    queue<int>q;
	    
	    for(int i=0;i<N;i++)
	    for(int j: adj[i])
	    id[j]++;
	    
	    
	    
	    for(int i=0; i<N;i++)
	    if(id[i] == 0) q.push(i);
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for(int i: adj[node])
	        {
	            id[i]--;
	            if(id[i] == 0) q.push(i);
	        }
	    }
	    
	    if(ans.size() == N) return 1;
	    else return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends