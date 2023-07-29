//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void find(vector<string>&ans,string &ds, int n , int zeros,int ones){
        
        
        if(ds.size() == n){
            ans.push_back(ds);
            return ;
        }
        
        if(ones>= zeros){
            
            ds.push_back('1');
            find(ans,ds,n,zeros,ones+1);
            ds.pop_back();
            
        }
        
        
        if(zeros <  n/2){
            
            ds.push_back('0');
            find(ans,ds,n,zeros+1,ones);
            ds.pop_back();
        }
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string>ans;
	    string ds;
	    find(ans,ds,N,0,0);
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