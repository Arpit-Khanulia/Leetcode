class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
//         int count =0;
//         int sum = 0;
//         for(int i=0 ; i<nums.size();i++){
//             for(int j= i ; j<nums.size();j++){
                
//                 sum = sum + nums[j];
//                 if(sum%k == 0) count++;
//             }
//             sum =0;
//         }
        
//         return count;
        
        int size = nums.size();
        vector<int>psm(size+1);
        int sum =0;
        psm[0] = 0;
        for(int i=0 ; i<size; i++){
            
            sum = sum + nums[i];
            
            int rem = sum%k; 
            if(rem<0) rem = rem + k;
            psm[i+1] = rem;
        }
        
        map<int,int>m;
        
        for(int i: psm)
            m[i]++;
        
        int count =0;
        for(auto i: m)
            if(i.second >1)
            {
                count = count + (i.second * (i.second -1))/2;
            }
        
        return count;

    // int n = nums.size();
    // int count = 0;
    // unordered_map<int, int> rem_freq{{0, 1}};
    // int cum_sum = 0;
    // for (int i = 0; i < n; i++) {
    //     cum_sum += nums[i];
    //     int rem = cum_sum % k;
    //     if (rem < 0) rem += k;
    //     if (rem_freq.count(rem)) count += rem_freq[rem];
    //     if (rem_freq.count(rem)) rem_freq[rem]++;
    //     else rem_freq[rem] = 1;
    // }
    // return count;

        
        
    }
};