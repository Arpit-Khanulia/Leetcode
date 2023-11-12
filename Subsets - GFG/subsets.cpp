//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void find(vector<int>&a, vector<vector<int>>&ans,int i,vector<int>ds){
        
        
        if(i >= a.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(a[i]);
        find(a,ans,i+1,ds);
        
        ds.pop_back();
        find(a,ans,i+1,ds);
        
        
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<int>ds;
        vector<vector<int>>ans;
        find(A,ans,0,ds);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends