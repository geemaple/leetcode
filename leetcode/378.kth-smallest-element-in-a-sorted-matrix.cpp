//  Tag: Array, Binary Search, Sorting, Heap (Priority Queue), Matrix
//  Time: O(KlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
//  Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//  You must find a solution with a memory complexity better than O(n2).
//   
//  Example 1:
//  
//  Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
//  Output: 13
//  Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
//  
//  Example 2:
//  
//  Input: matrix = [[-5]], k = 1
//  Output: -5
//  
//   
//  Constraints:
//  
//  n == matrix.length == matrix[i].length
//  1 <= n <= 300
//  -109 <= matrix[i][j] <= 109
//  All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
//  1 <= k <= n2
//  
//   
//  Follow up:
//  
//  Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
//  Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.
//  
//  

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
        for (int i = 0; i < n; i++) {
            heap.emplace(matrix[i][0], i, 0);
        }

        for (int i = 1; i < k; i++) {
            auto [cur, x, y] = heap.top();
            heap.pop();
            if (y + 1 < n) {
                heap.emplace(matrix[x][y + 1], x, y + 1);
            }
        }

        auto [cur, x, y] = heap.top();
        return cur;
    }
};

// follow up
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();

        while (left < right) {
            int mid = (left + right) >> 1;
            if (count_less_equal(matrix, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int count_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col += 1;
            } else {
                row -= 1;
            }
        }
        return count;
    }
};