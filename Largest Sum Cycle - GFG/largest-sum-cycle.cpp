//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  
  void dfs(vector<int>&adj,vector<int>&vi,vector<int>&extra,vector<int>&distance,int &ans,int& node,int d){
      
    if(node != -1)
    {
          if(!vi[node])
          {
            vi[node] = 1;
            extra[node] = 1;
            distance[node] = d;
            dfs(adj,vi,extra,distance,ans,adj[node],d+node);
              
          }
          
          else if(extra[node])
          ans = max(ans, d - distance[node]);


      
      extra[node] =0;
      
    }
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    
    int ans=-1;
    vector<int>vi(N);
    vector<int>extra(N);
    vector<int>distance(N);
    
    for(int i=0; i<N;i++)
    if(!vi[i]) dfs(Edge,vi,extra,distance,ans,i,0);
    
    return ans;
    
    
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends