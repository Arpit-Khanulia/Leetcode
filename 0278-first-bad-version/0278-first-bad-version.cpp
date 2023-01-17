// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        
        long long int i=0; 
        long long int j=n;
        
        while(i<=j){
            
            long long int mid = (i+j)/2;
            
            
            bool result = isBadVersion(mid);
            
            if( result == true) {
                
                if(isBadVersion(mid-1) == false) return mid;
                
                j = mid-1;
            }
            else if(result == false){
                
                if(isBadVersion(mid+1) == true) return mid+1;
                i = mid+1;
            }
                
              
        }
        
        return i;
        
    }
};