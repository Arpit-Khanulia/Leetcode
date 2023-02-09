//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        map<char,int>m;
        
        for(char i: s)
        m[i]++;
        
        m['l'] /=2; 
        m['o'] /=2; 
        
        
        int mini = INT_MAX;
        for(auto i: m)
        if(i.first == 'b' or i.first == 'a' or i.first == 'l' or i.first == 'o' or i.first == 'n')
        mini = min(i.second,mini);
        
        
        return mini;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends