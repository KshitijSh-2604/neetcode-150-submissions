class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        function<void(int, int)> dfs = [&](int index, int rsum) {
            if (rsum == 0)
            {
                ans.emplace_back(curr);
                return;
            }
            if (nums[index] > rsum)
            {
                return;
            }
            for (int j=index; j<nums.size(); j++)
            {
                curr.push_back(nums[j]);
                dfs(j, rsum-nums[j]);
                curr.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
