class Solution {
public:
    vector<string> ans;
    vector<string> dTC = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            return ans;
        }
        backtrack(0, "", digits);
        return ans;
    }
    void backtrack(int i, string curStr, string &digits) {
        if (curStr.size() == digits.size())
        {
            ans.push_back(curStr);
            return;
        }
        string chars = dTC[digits[i]-'0'];
        for (char c : chars)
        {
            backtrack(i+1, curStr+c, digits);
        }
    }
};