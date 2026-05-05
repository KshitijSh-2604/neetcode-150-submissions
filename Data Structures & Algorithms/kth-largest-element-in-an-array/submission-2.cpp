#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r)
        {
            return nums[l];
        }
        int pivotIndex = l+(rand()%(r-l+1));
        swap(nums[pivotIndex], nums[r]);
        int pivot = nums[r];
        int p = l;
        for (int i=l; i<r; i++)
        {
            if (nums[i] <= pivot)
            {
                swap(nums[p], nums[i]);
                p++;
            }
        }
        swap(nums[p], nums[r]);
        if (p == k)
        {
            return nums[p];
        }
        else if (p > k)
        {
            return quickSelect(nums, l, p-1, k);
        }
        else
        {
            return quickSelect(nums, p+1, r, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size()-k;
        return quickSelect(nums, 0, nums.size()-1, target);
    }
};