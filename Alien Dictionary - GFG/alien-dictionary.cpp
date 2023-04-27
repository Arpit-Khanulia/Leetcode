//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int>adj[K];
        
        for(int i=0; i<N-1;i++){
            
            string a = dict[i];
            string b = dict[i+1];
            
            int size = min(a.size(),b.size());
            
            for(int j=0; j<size;j++){
                
                if(a[j] != b[j]) 
                {
                    adj[ a[j] -'a'].push_back(b[j] - 'a');
                    break;
                }
            }
        }
        
        
        vector<int>indgree(K);
        vector<int>ans;
        queue<int>q;
        
        
        for(int i=0; i<K;i++){
            for(int j : adj[i]){
                indgree[j]++;
            }
        }
        
        for(int i =0; i<indgree.size();i++){
            if(indgree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i : adj[node]){
                
                indgree[i]--;
                if(indgree[i] == 0) q.push(i);
            }
        }
        
        string answer ="";
        for(int i : ans) answer = answer + char( i + 'a');
        return answer;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends