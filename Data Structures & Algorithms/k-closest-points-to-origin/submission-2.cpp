class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (auto& p : pts)
        {
            int dist = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({dist, {p[0], p[1]}});
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty())
        {
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        return ans;
    }
};