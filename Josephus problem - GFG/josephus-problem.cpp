//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    
    void find(vector<int>&circle,int k,int start){
        
        if(circle.size() == 1) return ;
        
        int del = (start + k-1)%circle.size();
        circle.erase(circle.begin() + del);
        find(circle,k,del);
        
    }
    int josephus(int n, int k)
    {
       //Your code here
       
       vector<int>circle(n);
       for(int i =0; i<circle.size();i++) circle[i] =i+1;
       
       
       find(circle,k,0);
       
       return circle[0];
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends