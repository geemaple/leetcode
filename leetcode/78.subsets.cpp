class Solution {
private:
    void dfsTraversal(vector<int>& nums, int start, vector<int> &tmp, vector<vector<int>> &result){
        //push_back will copy tmp, no need to copy manually
        result.push_back(tmp);
        
        for (auto i = start; i < nums.size(); ++i)
        {
            tmp.push_back(nums[i]);
            dfsTraversal(nums, i + 1, tmp, result);
            tmp.pop_back();
        }
    }
public:
    // bit manipulation
    // O(N * 2^N)
    /*
     suppose [1, 2, 3] initially the 8 subsets are all empty
     a way to visualize this idea. That is,
     1 appears once in every two consecutive subsets,
     2 appears twice in every four consecutive subsets,
     3 appears four times in every eight subsets, shown in the following:
     [], [], [], [], [], [], [], []
     
     [], [1], [], [1], [], [1], [], [1]
     
     [], [1], [2], [1, 2], [], [1], [2], [1, 2]
     
     [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size());
        vector<vector<int> > res(num_subset, vector<int>());
        for (auto i = 0; i < nums.size(); ++i)
        {
            for (auto j = 0; j < num_subset; ++j)
            {
                if ((j >> i) & 1){
                    res[j].push_back(nums[i]);
                }
            }
        }
        
        return res;
    }
    
    // iterative
    // 2^0 + 2^1 + ... + 2^N = O(2^N) * O(N)
    vector<vector<int>> subsets2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1, vector<int>());
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            int n = res.size();
            for (auto j = 0; j < n; ++j)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]); // O(N)
            }
        }
        
        return res;
    }
    
    // backtracing
    // O(N * 2^N); O(2^N) solusions muliply each need O(N) to construct a array result
    vector<vector<int>> subsets3(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        
        sort(nums.begin(), nums.end());
        dfsTraversal(nums, 0, tmp, res);
        
        return res;
    }
};
