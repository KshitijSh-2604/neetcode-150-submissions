class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, left = height[l], right = height[r], ans = 0;
        if (height.empty())
        {
            return 0;
        }
        while (l < r)
        {
            if (left < right)
            {
                l++;
                left = max(left, height[l]);
                ans += left-height[l];
            }
            else
            {
                r--;
                right = max(right, height[r]);
                ans += right-height[r];
            }
        }
        return ans;
    }
};
