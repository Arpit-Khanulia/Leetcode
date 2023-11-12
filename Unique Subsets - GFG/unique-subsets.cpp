//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    
    void find(vector<vector<int>>&ans,vector<int>&arr,int i, vector<int>&ds){
        
        
        if(i>= arr.size()){
            
            ans.push_back(ds);
            return;
        }
        
        
        
        ds.push_back(arr[i]);
        
        
        find(ans,arr,i+1,ds);
        ds.pop_back();
        
        int k =i+1;
        while(k<arr.size() and arr[i] == arr[k]){
            k++;
        }
        
        find(ans,arr,k,ds);
        
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>>ans;
        vector<int>ds;
        sort(arr.begin(),arr.end());
        
        find(ans,arr,0,ds);
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends