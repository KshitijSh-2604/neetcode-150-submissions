class SegmentTree {
public:
    int n;
    vector<int> tree;
    void build(int N, vector<int>& A)
    {
        n = N;
        tree.assign(2*n, INT_MIN);
        for (int i=0; i<n; i++)
        {
            tree[n+i] = A[i];
        }
        for (int i=n-1; i>0; i--)
        {
            tree[i] = max(tree[2*i], tree[2*i+1]);
        }
    }
    int query(int l, int r)
    {
        int res = INT_MIN;
        l += n;
        r += n+1;
        while (l < r)
        {
            if (l & 1)
            {
                res = max(res, tree[l]);
                l++;
            }
            if (r & 1)
            {
                r--;
                res = max(res, tree[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree segTree;
        segTree.build(n, nums);
        vector<int> output;
        for (int i=0; i<=n-k; i++)
        {
            output.push_back(segTree.query(i, i+k-1));
        }
        return output;
    }
};