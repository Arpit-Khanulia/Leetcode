//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    map<char,int>m1;
	    map<char,int>m2;
	    for(auto i : pat) m1[i]++;
	    
	    int low =0;
	    int high =0;
	    int count =0;
	    
	    while(high <= txt.size()-1){
	        
	        m2[txt[high]]++;
	        
	        if(high - low + 1 == pat.size()){
	           
	            if(m2 == m1) count++;

	            m2[txt[low]]--;
	            if(m2[txt[low]] == 0) m2.erase(txt[low]);
	            low++;
	        }
	        high++;
	    }
	    
	    return count;
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends