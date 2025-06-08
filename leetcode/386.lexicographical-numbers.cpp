//  Tag: Depth-First Search, Trie
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/RXey_UB7wKo

//  Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
//  You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
//   
//  Example 1:
//  Input: n = 13
//  Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
//  Example 2:
//  Input: n = 2
//  Output: [1,2]
//  
//   
//  Constraints:
//  
//  1 <= n <= 5 * 104
//  
//  

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(cur);
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur >= n) {
                    cur /= 10;
                }
                cur += 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int cur, int n, vector<int> &res) {
        if (cur > n) {
            return;
        }
        res.push_back(cur);
        for (int i = 0; i <= 9; i++) {
            dfs(cur * 10 + i, n, res);
        }
    }
};