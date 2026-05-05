class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k)
    {
        auto comp = [](auto& a, auto& b)
        {
            return (a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
        for (auto& p : pts)
        {
            minHeap.push({p[0], p[1]});
        }
        vector<vector<int>> ans;
        for (int i=0; i<k; i++)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
    }
};