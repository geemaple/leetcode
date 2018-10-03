// f[i][w] = f[i - 1][w] + f[i - 1][w - A[i - 1]]
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        vector<int> table(target + 1, 0);
        table[0] = 1;

        for (auto i = 0; i < nums.size(); ++i)
        {
            for (auto w = target; w >=0; --w)
            {
                int value = table[w];
                if (w - nums[i] >= 0)
                {
                    value += table[w - nums[i]];
                }
                table[w] = value;
            }
        }

        return table[target];
    }
};