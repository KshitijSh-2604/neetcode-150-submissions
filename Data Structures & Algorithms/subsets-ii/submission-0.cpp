class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bt(nums, 0, {});
        return ans;
    }
    void bt(vector<int>& nums, int i, vector<int> subset)
    {
        if (i == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        bt(nums, i+1, subset);
        subset.pop_back();
        while (i+1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }
        bt(nums, i+1, subset);
    }
};
