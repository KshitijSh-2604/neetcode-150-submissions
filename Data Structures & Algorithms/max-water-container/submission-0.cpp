class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1, ans = 0, mx;
        while (l < r)
        {
            mx = min(heights[l], heights[r]) * (r-l);
            ans = max(ans, mx);
            if (heights[l] <= heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
