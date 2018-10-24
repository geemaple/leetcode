struct cmp
{
    bool operator()(pair<int, int>&a, pair<int, int>&b)
    {
        return a.first < b.first;
    }
};

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<pair<int, int>> prefix_sum;
        prefix_sum.push_back(make_pair(0, -1));
        
        for(auto i = 0; i < nums.size(); ++i)
        {
            int sum = nums[i] + prefix_sum[prefix_sum.size() - 1].first;
            prefix_sum.push_back(make_pair(sum, i));
        }
        
        sort(prefix_sum.begin(), prefix_sum.end(), cmp());
        int closest = INT_MAX;
        vector<int> ans(2, 0);
        
        for (auto i = 1; i < prefix_sum.size(); ++i)
        {
            if (abs(prefix_sum[i].first - prefix_sum[i - 1].first) < closest)
            {
                closest = abs(prefix_sum[i].first - prefix_sum[i - 1].first);
                ans[0] = min(prefix_sum[i].second, prefix_sum[i - 1].second) + 1;
                ans[1] = max(prefix_sum[i].second, prefix_sum[i - 1].second);
            }
        }
    
        return ans;
        
    }
};