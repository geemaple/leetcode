//  Tag: Array, Binary Search, Greedy, Sorting
//  Time: O(NlogN + NlogD)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].
//  You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen integers is defined as the minimum absolute difference between any two integers that have been chosen.
//  Return the maximum possible score of the chosen integers.
//   
//  Example 1:
//  
//  Input: start = [6,0,3], d = 2
//  Output: 4
//  Explanation:
//  The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is min(|8 - 0|, |8 - 4|, |0 - 4|) which equals 4.
//  
//  Example 2:
//  
//  Input: start = [2,6,13,13], d = 5
//  Output: 5
//  Explanation:
//  The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|) which equals 5.
//  
//   
//  Constraints:
//  
//  2 <= start.length <= 105
//  0 <= start[i] <= 109
//  0 <= d <= 109
//  
//  

class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long left = 0;
        long long right = start.back() - start.front() + d;

        while (left < right) {
            long long mid = (left + right + 1) >> 1;
            if (fit(start, d, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    bool fit(vector<int>& start, int d, int ans) {
        long long pos = start[0];
        for (int i = 1; i < start.size(); i++) {
            pos = max(start[i] * 1LL, pos + ans);
            if (pos > start[i] + d) {
                return false;
            }
        }
        return true;
    }
};