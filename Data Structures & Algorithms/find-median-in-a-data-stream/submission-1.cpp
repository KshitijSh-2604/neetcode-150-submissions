class MedianFinder {
    priority_queue<int, vector<int>, less<int>> sH;
    priority_queue<int, vector<int>, greater<int>> lH;
public:
    MedianFinder() {}
    void addNum(int num)
    {
        sH.push(num);
        if (!lH.empty() && sH.top() > lH.top()) {
            lH.push(sH.top());
            sH.pop();
        }
        if (sH.size() > lH.size() + 1) {
            lH.push(sH.top());
            sH.pop();
        }
        if (lH.size() > sH.size() + 1) {
            sH.push(lH.top());
            lH.pop();
        }
    }
    double findMedian() {
        if (sH.size() == lH.size()) {
            return (lH.top() + sH.top()) / 2.0;
        } else if (sH.size() > lH.size()) {
            return sH.top();
        } else {
            return lH.top();
        }
    }
};