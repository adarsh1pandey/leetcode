class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<int>> row(9), column(9), box(9);
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int curr = board[i][j] - '0';
                if (row[i].count(curr) ||  column[j].count(curr) || box[(i/3 *3 + j/3)].count(curr))
                    return false;
                row[i].insert(curr);
                column[j].insert(curr);
                box[(i/3*3 +j/3)].insert(curr);
            }
        }
        return true;
        
    }
};