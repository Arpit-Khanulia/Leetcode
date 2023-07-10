//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here

        long long ans =0;
        int size =n;
                         
        vector<int>maxleft(size);
        vector<int>maxright(size);
        
        maxleft[0] = height[0];
        maxright[size-1] = height[size-1];
        
        for(int i=1; i<size;i++) maxleft[i] = max(maxleft[i-1],height[i]);
        for(int j=size-2; j>=0; j--) maxright[j] = max(maxright[j+1],height[j]);

        
        for(int i=0; i<size;i++) ans += min(maxleft[i],maxright[i]) - height[i];
        
        return ans;   
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends