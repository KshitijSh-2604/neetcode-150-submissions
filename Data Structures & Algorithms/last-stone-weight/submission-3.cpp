class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int s : stones)
        {
            maxHeap.push(s);
        }
        while (maxHeap.size() > 1)
        {
            int one = maxHeap.top();
            maxHeap.pop();
            int two = maxHeap.top();
            maxHeap.pop();
            if (two < one)
            {
                maxHeap.push(one-two);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};