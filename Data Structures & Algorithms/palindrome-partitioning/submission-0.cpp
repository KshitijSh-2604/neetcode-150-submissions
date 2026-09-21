class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        dfs(0, s, part, ans);
        return ans;
    }
private:
    void dfs(int i, string& s, vector<string>& part, vector<vector<string>>& ans) {
        if (i >= s.length())
        {
            ans.push_back(part);
            return;
        }
        for (int j=i; j<s.length(); j++)
        {
            if (isPali(s, i, j))
            {
                part.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, part, ans);
                part.pop_back();
            }
        }
    }
    bool isPali(string& s, int l, int r) {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++; r--;
        }
        return true;
    }
};