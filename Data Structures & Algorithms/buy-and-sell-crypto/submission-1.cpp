class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxP = 0;
        int minBuy = prices[0];
        for (int& sell : prices)
        {
            mxP = max(mxP, sell-minBuy);
            minBuy = min(minBuy, sell);
        }
        return mxP;
    }
};