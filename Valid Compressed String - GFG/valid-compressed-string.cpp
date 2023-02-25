//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        
        int i =0; 
        int j =0;
        
        int sizet = T.size();
        int sizes = S.size();
        
        while(i<sizet){
            
            
            if( isalpha(T[i])){
                
                if(T[i] == S[j]){
                    i++;
                    j++;
                    continue;
                }
                else return 0;
            }
            else{
                
                string num ="";
                while(i< sizet and isdigit(T[i])){
                    
                    num = num + T[i];
                    i++;
                }
                j = j+ stoi(num);
            }
        }
        
        if(j == sizes) return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends