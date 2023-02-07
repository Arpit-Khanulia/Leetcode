class Solution {
public:
    /*
        Solve with sliding window,
        and maintain a hashmap counter,
        which count the number of element between the two pointers.
    */
    int totalFruit(vector<int>& fruits) {
        //Declare basket for storing amounts of fruits of type i
        map<int,int> basket;
        int mx=0;
        
        int i=0, j=0;
		int n=fruits.size();
        while(i < n){
            
            //Increment the fruits[i] at each iteration
            ++basket[fruits[i]];
            
            
            //If we reach the limit, decrement starting from 0th index 
            //till we have only two types of fruit in our basket
            
            //If the amount turns out to be zero for particular type, erase that type from hashmap as we have came across 0 fruits of type j.
            while(j < n && (int)basket.size() > 2){
                if(basket[fruits[j]] == 1)
                    basket.erase(fruits[j]);
                else
                    --basket[fruits[j]];
                ++j;
            }
            
            //Maximize the result from j.....i , i.e, count of fruits from jth till ith index for 2 sized window
            mx=max(mx, i-j+1);
            ++i;
        }
        return mx;  // :)
    }
};