class Solution {
    int r, c;
    set<pair<int, int>> path;
public:
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();
        for (int R=0; R<r; R++)
        {
            for (int C=0; C<c; C++)
            {
                if (dfs(board, word, R, C, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int R, int C, int i)
    {
        if (i == word.length())
        {
            return true;
        }
        if (R<0 || C<0 || R>=r || C>=c || board[R][C]!=word[i] || path.count({R,C}))
        {
            return false;
        }
        path.insert({R,C});
        bool ans = dfs(board, word, R+1, C, i+1) || dfs(board, word, R-1, C, i+1) || dfs(board, word, R, C+1, i+1) || dfs(board, word, R, C-1, i+1);
        path.erase({R,C});
        return ans;
    }
};
