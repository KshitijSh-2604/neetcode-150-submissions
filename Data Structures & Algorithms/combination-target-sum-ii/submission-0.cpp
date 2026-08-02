class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        function<void(int, int)> dfs = [&](int index, int rSum)
        {
            if (rSum == 0)
            {
                ans.emplace_back(curr);
            }
            if (index >= nums.size() || rSum < nums[index])
            {
                return;
            }
            for (int i=index; i<nums.size(); i++)
            {
                if (i>index && nums[i]==nums[i-1])
                {
                    continue;
                }
                curr.emplace_back(nums[i]);
                dfs(i+1, rSum-nums[i]);
                curr.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
