class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> M;
        for (int i=0; i<strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            M[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto i : M)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
