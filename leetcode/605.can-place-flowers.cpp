//  Tag: Greedy, Array
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
//  Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
//   
//  Example 1:
//  Input: flowerbed = [1,0,0,0,1], n = 1
//  Output: true
//  Example 2:
//  Input: flowerbed = [1,0,0,0,1], n = 2
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= flowerbed.length <= 2 * 104
//  flowerbed[i] is 0 or 1.
//  There are no two adjacent flowers in flowerbed.
//  0 <= n <= flowerbed.length
//  
//  

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                count ++;
                flowerbed[i] = 1;
            }
        }

        return count >= n;
    }
};