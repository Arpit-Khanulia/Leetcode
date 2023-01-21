class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int N=matrix.size();
      for(int i=0; i<N; i++)
         if(binary_search(matrix[i].begin(), matrix[i].end(), target)==true)
                return 1;
    return 0;
}
};