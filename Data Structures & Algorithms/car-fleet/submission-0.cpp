class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i=0; i<pos.size(); i++)
        {
            pair.push_back({pos[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> st;
        for (auto& p : pair)
        {
            st.push_back((double)(target-p.first)/p.second);
            if (st.size()>=2 && st.back()<=st[st.size()-2])
            {
                st.pop_back();
            }
        }
        return st.size();
    }
};