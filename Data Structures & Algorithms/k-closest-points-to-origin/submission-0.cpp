class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        sort(pts.begin(), pts.end(), [](auto& a, auto& b) {
            return (a[0]* a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        return vector<vector<int>>(pts.begin(), pts.begin() + k);
    }
};