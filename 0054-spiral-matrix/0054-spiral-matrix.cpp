class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = n, u = 0, d = m;

        while (l < r && u < d)
        {
            if (l < r && u < d)
                for (int i = l; i < r; i++)
                    ans.push_back(matrix[u][i]);

            u++;

            if (l < r && u < d)
                for (int i = u; i < d; i++)
                    ans.push_back(matrix[i][r - 1]);

            r--;
            if (l < r && u < d)
                for (int i = r - 1; i >= l; i--)
                    ans.push_back(matrix[d - 1][i]);

            d--;
            if (l < r && u < d)
                for (int i = d - 1; i >= u; i--)
                    ans.push_back(matrix[i][l]);

            l++;
        }

        return ans;
    }
};