class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m;
        if (n >= 1)
        {
            m = matrix[0].size();
        }
        int row = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][m -1] >= target)
            {
                row = i;
                break;
            }
        }
        for(int j = 0; j < m; j++)
        {
            if (matrix[row][j] == target)
            {
                return true;
            }
        }
        return false;
    }
};