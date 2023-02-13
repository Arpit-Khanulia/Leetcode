class Solution {
public:
    int countOdds(int low, int high) {
        double l =low;
        double h = high;        
        if(low%2==0 && high %2==0) return (high -low)/2;
        if(low%2!=0 && high %2!=0) return (high -low)/2 +1;
        return ceil((h -l)/2);
        
    }
};