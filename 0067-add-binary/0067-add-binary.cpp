class Solution {
public:
    string addBinary(string a, string b) {
        
        
        int c= 0;
        string ans;
        
        int i=a.size()-1;
        int j=b.size()-1;
        
        while(i>=0 || j>=0 || c ){
            
            int sum= 0;
            if(i>=0)
            sum += a[i] -'0';
            
            if(j>=0)
            sum += b[j] -'0';
            
            sum =  sum + c;
            string q = to_string(sum%2);
            ans += q;
            c = sum/2;
            i--;
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};