class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ft, win;
        if (t.empty())
        {
            return "";
        }
        for (char c : t)
        {
            ft[c]++;
        }
        int have = 0, need = ft.size();
        pair<int, int> ans = {-1, -1};
        int len = INT_MAX, l = 0;
        for (int r=0; r<s.length(); r++)
        {
            char c = s[r];
            win[c]++;
            if (ft.count(c) && win[c]==ft[c])
            {
                have++;
            }
            while (have == need)
            {
                if ((r-l+1) < len)
                {
                    len = r-l+1;
                    ans = {l, r};
                }
                win[s[l]]--;
                if (ft.count(s[l]) && win[s[l]]<ft[s[l]])
                {
                    have--;
                }
                l++;
            }
        }
        return ((len==INT_MAX) ? "" : s.substr(ans.first, len));
    }
};
