//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void find(vector<string>&ans,string ds,string s, int i){
        
        
        if(i == s.size()-1){
            ds.push_back(s[i]);
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(s[i]);
        ds.append(" ");
        
        find(ans,ds,s,i+1);
        ds.pop_back();
        find(ans,ds,s,i+1);
        
    }
    
    vector<string> permutation(string S){
        // Code Here
        
        vector<string>ans;
        string ds;
        find(ans,ds,S,0);
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