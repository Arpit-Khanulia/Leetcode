//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int>distance(100000,1e9);
        distance[start] =0;
        
        queue<pair<int,int>>q;
        q.push({0,start});
        
        while(!q.empty()){
            
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == end) return steps;
            
            for(int i: arr){
                
                int temp = node*i % 100000;
                
                if(distance[temp] > steps+1) {
                    
                    distance[temp] = steps+1;
                    q.push({steps+1, temp});
                }
            }
        }
        
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends