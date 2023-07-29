class Solution {
public:
//  0<3 (, 1<3 ( , 2<3(, 0 <3 ), 1<3 ) , 2<3 ),      
    void find(vector<string>&ans,string ds, int n, int open , int close){
        
        
        if(open ==n and  close == n){
            
            ans.push_back(ds);
            return;
        }
        
        if(open < n){
            ds.push_back('(');
            find(ans,ds,n,open+1,close);
            ds.pop_back(); 
        }
        
        if(close<n and close < open ){
            ds.push_back(')');
            find(ans,ds,n,open,close+1);
            ds.pop_back();         
        }  

    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        string ds;
        find(ans,ds,n,0,0);
        return ans;
        
    }
};