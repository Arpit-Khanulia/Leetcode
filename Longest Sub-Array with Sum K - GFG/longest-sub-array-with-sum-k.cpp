//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        // Complete the function
        
        int sum=0;
        map<int,int>m;
        int maxi = 0;
        
        
        for(int i=0; i<n;i++){
            
            sum = sum + nums[i];
            if(m.find(sum) == m.end()) m[sum] = i; 
            
            if(sum == k) maxi = max(maxi,i+1);
            
            else if(m.find(sum-k) != m.end()){
                maxi = max(maxi,i-m[sum-k]);
            }
        }

        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends