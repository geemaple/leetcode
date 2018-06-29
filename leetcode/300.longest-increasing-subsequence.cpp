class Solution {
private:
    // find the smallest possible index which it's value >= key
    int ceilIndex(vector<int> v, int left, int right, int key){
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (v[mid] < key)
            {
                left = mid;
            }else{
                right = mid;
            }
        }
        
        if (v[right] >= key)
        {
            return right;
        }
        
        return left;
    }
public:
    // O(N * LogN)
    // Ref: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
    // With some modification:
    // 1. change first <if> in for-loop from < to <=
    // 2. change binary search calling starting point from -1 to 1
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        vector<int> tails(nums.size(), 0);
        tails[0] = nums[0];
        int length = 1; // always points empty slot in tails
        
        for (auto i = 1; i < nums.size(); ++i)
        {
            if (nums[i] <= tails[0])
            {
                // new smallest value
                tails[0] = nums[i];
            }
            else if (nums[i] > tails[length - 1])
            {
                // v[i] extends largest subsequence
                tails[length] = nums[i];
                length += 1;
            }
            else
            {
                int index = ceilIndex(tails, 0, length - 1, nums[i]);
                tails[index] = nums[i];
            }
        }
        
        return length;
    }
    
    // O(N^2)
    int lengthOfLIS2(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        vector<int> table;
        table.push_back(1);
        
        for (auto i = 1; i < nums.size(); ++i)
        {
            int count = 1;
            for (auto j = 0; j < table.size(); ++j)
            {
                if (nums[i] > nums[j] && count < table[j] + 1)
                {
                    count = table[j] + 1;
                }
            }
            
            table.push_back(count);
        }
        
        return *max_element(table.begin(), table.end());
    }
};
