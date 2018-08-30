class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // write your code here
        // default is max queue, use greater comparator to make a min queue
        priority_queue<int, vector<int>, greater<int>> pq; 

        for (auto list: arrays)
        {
            for (auto num: list)
            {
                if (pq.size() < k)
                {
                    pq.push(num);
                }
                else if (pq.top() < num)
                {
                    pq.pop();
                    pq.push(num);
                }
            }
        }

        return pq.top();
    }
};