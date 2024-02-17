class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        for(int col = 0; col <m; col++)
        {
            int maxi = INT_MIN;
            for(int row = 0; row < n; row++)
            {
                maxi = max(maxi, matrix[row][col]);
            }

            res.push_back(maxi);
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = res[j];
                }
            }
        }

        return matrix;
    }
};
