class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedRows[9][9] = {0};
        int usedCols[9][9] = {0};
        int usedSubgrids[9][9] = {0};
        for (int i=0; i<board.size(); i++)
        {
            for (int j=0; j<board[i].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j]-'0'-1;
                    int subgridIndex = (i/3)*3 + j/3;
                    if (usedRows[i][num] || usedCols[j][num] || usedSubgrids[subgridIndex][num])
                    {
                        return false;
                    }
                    usedRows[i][num] = usedCols[j][num] = usedSubgrids[subgridIndex][num] = 1;
                }
            }
        }
        return true;
    }
};
