class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>& ans, string& s) {
        if (open == close && open == n)
        {
            ans.push_back(s);
            return;
        }
        if (open < n)
        {
            s += '(';
            backtrack(open+1, close, n, ans, s);
            s.pop_back();
        }
        if (close < open)
        {
            s += ')';
            backtrack(open, close+1, n, ans, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        backtrack(0, 0, n, ans, s);
        return ans;
    }
};