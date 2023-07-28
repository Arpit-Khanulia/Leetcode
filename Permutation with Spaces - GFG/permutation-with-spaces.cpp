//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void solve(string &s, string ds, vector<string>&ans,int i){
        
        if(i == s.size()-1) {
            ds.push_back(s[i]);
            ans.push_back(ds);
            return ;
        }
        
        ds.push_back(s[i]);
        
        solve(s,ds,ans,i+1);
        
        ds.append(" ");
        solve(s,ds,ans,i+1);
    }
    vector<string> permutation(string S){
        // Code Here
        
        string ds;
        vector<string>ans;
        solve(S,ds,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends