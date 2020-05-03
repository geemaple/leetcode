/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (41.25%)
 * Total Accepted:    193.6K
 * Total Submissions: 469.3K
 * Testcase Example:  '6'
 *
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 * Example 1:
 * 
 * 
 * Input: 6
 * Output: true
 * Explanation: 6 = 2 × 3
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: true
 * Explanation: 8 = 2 × 2 × 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 14
 * Output: false 
 * Explanation: 14 is not ugly since it includes another prime factor 7.
 * 
 * 
 * Note:
 * 
 * 
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
 * 
 */
class Solution {
public:
    bool isUgly(int num) {
        
        if (num <= 0) {
            return false;
        }

        int primes[] = {2, 3, 5};
        int test = num;
        for (int i = 0; i < sizeof(primes)/sizeof(int); i++) {
            int n = primes[i];
            while (test % n == 0) {
                test = test / n;
            }
        }
        
        return test == 1;
    }
};