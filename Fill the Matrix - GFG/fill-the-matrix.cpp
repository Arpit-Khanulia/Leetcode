//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        
        x--;
        y--;
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{x,y},0});
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        
        
        vector<vector<int>>vi(N,vector<int>(M));
    
        vi[x][y] =1;
        
        int maxd = 0;
        
        while(!q.empty()){
            
            int a = q.front().first.first;
            int b = q.front().first.second;
            int d = q.front().second;
            
            q.pop();
            
            maxd = max(d,maxd);
            
            for(int i=0; i<4; i++){
                
                int row = a + drow[i];
                int col = b + dcol[i];
                
                if(row>=0 and row<N and col>=0 and col<M and !vi[row][col]){
                    
                    vi[row][col] =1;
                    q.push({{row,col},d+1});
                }
            }
            
            
        }
        
        return maxd;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends