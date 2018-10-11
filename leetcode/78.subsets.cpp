// backtracing
// O(N * 2^N); O(2^N) solusions muliply each need O(N) to construct a array result
class Solution {
private:
    void dfs(vector<int>& nums, int start, vector<int>& ans, vector<vector<int>>& results)
    {
        results.push_back(ans);

        for (auto i = start; i < nums.size(); ++i)
        {
            ans.push_back(nums[i]);
            dfs(nums, i + 1, ans, results);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return vector<vector<int>>(1, vector<int>());
        }

        vector<vector<int>> results;
        vector<int> ans;
        dfs(nums, 0, ans, results);

        return results;
    }
};

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
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return vector<vector<int>>(1, vector<int>());
        }

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
};

// iterative
// 2^0 + 2^1 + ... + 2^N = O(2^N) * O(N)
// suppose [1, 2, 3] initially and the results = [[]]
// copy every item and append nums[i] to new copy one
// for 1 [[], [1]]
// for 2 [[], [1], [2], [1, 2]]
// for 3 [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]] 
class Solution3 {
public:    
    vector<vector<int>> subsets(vector<int>& nums) {
   
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
};
