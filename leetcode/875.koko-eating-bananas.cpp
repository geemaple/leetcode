//  Tag: Array, Binary Search
//  Time: O(NlogA)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//  Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//  Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//  Return the minimum integer k such that she can eat all the bananas within h hours.
//   
//  Example 1:
//  
//  Input: piles = [3,6,7,11], h = 8
//  Output: 4
//  
//  Example 2:
//  
//  Input: piles = [30,11,23,4,20], h = 5
//  Output: 30
//  
//  Example 3:
//  
//  Input: piles = [30,11,23,4,20], h = 6
//  Output: 23
//  
//   
//  Constraints:
//  
//  1 <= piles.length <= 104
//  piles.length <= h <= 109
//  1 <= piles[i] <= 109
//  
//  

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (can_finish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool can_finish(vector<int>& piles, int k, int h) {
        int cost = 0;
        for (int x: piles) {
            cost += x / k + (x % k == 0 ? 0 : 1);
        }

        return cost <= h;
    }
};