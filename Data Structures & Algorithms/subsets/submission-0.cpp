class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> subset;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == nums.size())
            {
                answer.push_back(subset);
                return;
            }
            dfs(i+1);
            subset.push_back(nums[i]);
            dfs(i+1);
            subset.pop_back();
        };
        dfs(0);
        return answer;
    }
};
