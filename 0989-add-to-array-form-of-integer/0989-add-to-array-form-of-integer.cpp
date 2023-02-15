class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        vector<int>ans;
        vector<int>temp;
        
        
        while(k>0){
            temp.push_back(k%10);
            k/=10;
        }
        reverse(temp.begin(),temp.end());
        
        cout<<k<<endl;
        for(int i=0; i<temp.size();i++)
            cout<<temp[i]<<" ";
        cout<<endl;
        
        
        
        
        int c=0;
        
        int i=num.size()-1; 
        int j=temp.size()-1;
        
        while(i>=0 || j>=0 || c){
            
            int b=0;
            
            if(i>=0)
            b = b+num[i];
            
            if(j>=0)
            b = b+temp[j];
            
            b = b+c;
            
            c = b/10;
            ans.push_back(b%10);
            
            
            i--;
            j--;
        }
        
     reverse(ans.begin(),ans.end());
     return ans;   
    }
};