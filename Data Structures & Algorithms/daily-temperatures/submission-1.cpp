class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> result(temp.size(), 0);
        stack<int> st;
        for (int i=0; i<temp.size(); i++)
        {
            while (!st.empty() && temp[i]>temp[st.top()])
            {
                int index = st.top();
                st.pop();
                result[index] = i-index;
            }
            st.push(i);
        }
        return result;
    }
};
