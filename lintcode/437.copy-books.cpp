//  Tag: Binary Search, Dynamic Programming/DP, Binary Search on Answer, Partition DP
//  Time: O(N*logP)
//  Space: O(1)
//  Ref: -
//  Note: Answer | DP

//  Given `n` books and the `i-th` book has `pages[i]` pages.
//  There are `k` persons to copy these books.
//  
//  These books list in a row and each person can claim a continous range of books.
//  For example, one copier can copy the books from `i-th` to `j-th` continously, but he can not copy the 1st book, 2nd book and 4th book (without 3rd book).
//  
//  They start copying books at the same time and they all cost 1 minute to copy 1 page of a book.
//  What's the best strategy to assign books so that the slowest copier can finish at earliest time? 
//  
//  Return the shortest time that the slowest copier spends.
//  
//  ---
//  
//  **Example 1:**
//  
//  ```
//  Input: pages = [3, 2, 4], k = 2
//  Output: 5
//  Explanation: 
//      First person spends 5 minutes to copy book 1 and book 2.
//      Second person spends 4 minutes to copy book 3.
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: pages = [3, 2, 4], k = 3
//  Output: 4
//  Explanation: Each person copies one of the books.
//  ```
//  
//  The sum of book pages is less than or equal to 2147483647

#include <numeric>

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if (pages.size() == 0) {
            return 0;
        }

        int start = *std::max_element(pages.begin(), pages.end());
        int end = std::accumulate(pages.begin(), pages.end(), 0);

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (can_finish(pages, mid, k)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

    bool can_finish(vector<int> &pages, int minutes, int k) {
        int work = 0;
        int people = 1;

        for (auto &p : pages) {
            if (work + p > minutes) {
                work = p;
                people += 1;
            } else {
                work += p;
            }
        }

        return people <= k;
    }
};