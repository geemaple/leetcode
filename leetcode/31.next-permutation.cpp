/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.56%)
 * Total Accepted:    209.3K
 * Total Submissions: 698.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically(字典顺序) next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = (int)nums.size() - 2;
        while(start >= 0)
        {
            if (nums[start] < nums[start + 1]) break;
            start--;
        }
        
        if(start < 0)
        {
            reverse_array(nums, 0, nums.size() - 1);
            return;
        }
        
        int end = (int)nums.size() - 1;
        while (end > start)
        {
            if (nums[end] > nums[start]) break;
            end--;
        }
        
        swap(nums, start, end);
        reverse_array(nums, start + 1, nums.size() - 1);
        
    }
    
    void reverse_array(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
    
    void swap(vector<int>& nums, int start, int end)
    {
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
    }
};

// Q: 在所有由nums元素组成的数种，求比当前顺序排列大的最小组合
// A: [1, 2, 7, 4, 3, 1] -> [1,3,1,2,4,7]
// 从后往前起，找到第一组生序(2, 7), 记录2的位置i
// 从后往前起，找到第一个比i大的数字3记录j
// 交换i，j的位置后，i之后的数字仍然为降序
// 反转i之后的元素
