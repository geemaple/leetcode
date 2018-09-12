class Solution {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap; //left
    priority_queue<int, vector<int>, greater<int>> minHeap; //right

public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here

        vector<int> results;

        for (auto num: nums)
        {
            if (maxHeap.size() <= minHeap.size())
            {
                maxHeap.push(num);
            }
            else
            {
                minHeap.push(num);
            }

            int left = maxHeap.top();
            int right = minHeap.top();
            if (left > right) // exchange left and right
            {
                maxHeap.pop();
                maxHeap.push(right);

                minHeap.pop();
                minHeap.push(left);
            }

            results.push_back(maxHeap.top());
        }

        return results;
    }
};