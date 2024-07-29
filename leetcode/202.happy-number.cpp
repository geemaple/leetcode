//  Tag: Hash Table, Math, Two Pointers
//  Time: O(S)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Write an algorithm to determine if a number n is happy.
//  A happy number is a number defined by the following process:
//  
//  Starting with any positive integer, replace the number by the sum of the squares of its digits.
//  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//  Those numbers for which this process ends in 1 are happy.
//  
//  Return true if n is a happy number, and false if not.
//   
//  Example 1:
//  
//  Input: n = 19
//  Output: true
//  Explanation:
//  12 + 92 = 82
//  82 + 22 = 68
//  62 + 82 = 100
//  12 + 02 + 02 = 1
//  
//  Example 2:
//  
//  Input: n = 2
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= n <= 231 - 1
//  
//  

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cache;
        while (cache.count(n) == 0) {
            cache.insert(n);
            int tmp = 0;
            while (n > 0) {
                tmp += pow(n % 10, 2);
                n = n / 10;
            }

            if (tmp == 1) {
                return true;
            } else {
                n = tmp;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = next_node(slow);
            fast = next_node(fast);
            fast = next_node(fast);
        } while(slow != fast);

        return slow == 1;
    }

    int next_node(int n) {
        int res = 0;
        while (n > 0) {
            res += pow(n % 10, 2);
            n = n / 10;
        }
        return res;
    }
};