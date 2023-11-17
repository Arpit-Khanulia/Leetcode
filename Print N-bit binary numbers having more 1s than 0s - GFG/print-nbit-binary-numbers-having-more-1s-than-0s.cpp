//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void find(int one, int zero , string& ds,  vector<string>&ans,int n){
        
        if(one + zero == n){
            
            if(one>=zero) ans.push_back(ds);
            return;
        }
        
        
        
        ds.push_back('1');
        find(one+1,zero,ds,ans,n);
        ds.pop_back();
        
        if(zero< one){
            
            ds.push_back('0');
            find(one,zero+1,ds,ans,n);
            ds.pop_back();
        }
        
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    
	    string ds;
	    vector<string>ans;
	    ds.push_back('1');
	    find(1, 0, ds, ans,N);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends