//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void find(vector<string>&ans, string &ds, int i, string s){
        
        if(i == s.size()-1){
            
            ds.push_back(s[i]);
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        
        
        ds.push_back(s[i]);
        ds = ds+ " ";
        
        find(ans,ds,i+1,s);
        
        ds.pop_back();
        find(ans,ds,i+1,s);
        ds.pop_back();
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string>ans;
        string ds;
        find(ans,ds,0,S);
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