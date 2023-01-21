class Solution {
public:
    
    int check(string &ds, int pdot){
        
        cout<<"this is pdot "<<pdot<<endl;
        string sub = string(ds.begin() + pdot,ds.end());
        
        if(sub[0] == '0' && sub.size()>1) return 0;

        int no = stoi(sub);
        cout<<no<<" ";
        cout<<endl;
        
        if(no>255) return 0;
        
        return 1;
    }
    
    void solve(string &s, string ds, vector<string>&ans,int i,int pdot,int dcount){
        
        if(i == s.size()){

            cout<<"this is ds "<<ds<<endl;
            if(check(ds,pdot) && dcount == 3) ans.push_back(ds);
            return ;
        }
        
        ds.push_back(s[i]);
        
        if(check(ds,pdot)){
            
            solve(s,ds,ans,i+1,pdot,dcount);
        }
        
        if(ds.size() - pdot >1 && dcount <=2)
        {
            cout<<"This is the size -> "<<ds.size() - pdot+1<<endl;
            int size = ds.size()-1;
            ds[size] = '.';
            dcount++;
            solve(s,ds,ans,i,size+1,dcount);
     
        }

        
        
    }
    vector<string> restoreIpAddresses(string s) {
        
        string ds;
        vector<string>ans;
        
        solve(s,ds,ans,0,0,0);
        return ans;
        
    }
};