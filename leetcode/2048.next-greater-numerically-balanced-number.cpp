//  Tag: Hash Table, Math, Backtracking, Counting, Enumeration
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/yMjRNt9h1nQ

//  An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
//  Given an integer n, return the smallest numerically balanced number strictly greater than n.
//   
//  Example 1:
//  
//  Input: n = 1
//  Output: 22
//  Explanation: 
//  22 is numerically balanced since:
//  - The digit 2 occurs 2 times. 
//  It is also the smallest numerically balanced number strictly greater than 1.
//  
//  Example 2:
//  
//  Input: n = 1000
//  Output: 1333
//  Explanation: 
//  1333 is numerically balanced since:
//  - The digit 1 occurs 1 time.
//  - The digit 3 occurs 3 times. 
//  It is also the smallest numerically balanced number strictly greater than 1000.
//  Note that 1022 cannot be the answer because 0 appeared more than 0 times.
//  
//  Example 3:
//  
//  Input: n = 3000
//  Output: 3133
//  Explanation: 
//  3133 is numerically balanced since:
//  - The digit 1 occurs 1 time.
//  - The digit 3 occurs 3 times.
//  It is also the smallest numerically balanced number strictly greater than 3000.
//  
//   
//  Constraints:
//  
//  0 <= n <= 106
//  
//  

class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> counter = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int size = to_string(n).size();
        return dfs(n, 0, size, counter) ?: dfs(n, 0, size + 1, counter);
    }

    int dfs(int n, int val, int size, vector<int> &counter) {
        if (size == 0) {
            for (int i = 1; i <= 9; i++) {
                if (counter[i] == i) {
                    continue;
                }
                if (counter[i] != 0) {
                    return 0;
                }
            }
            return val > n ? val : 0;
        }

        int res = 0;
        for (int i = 1; i <= 9 && res == 0; i++) {
            if (counter[i] > 0 && counter[i] <= size) {
                counter[i] -= 1;
                res = dfs(n, val * 10 + i, size - 1, counter);
                counter[i] += 1;
            }
        }

        return res;
    }
};