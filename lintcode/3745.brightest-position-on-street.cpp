//  Tag: Prefix Sum Array, Array, Line Sweep
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-2237
//  Note: -

//  A street has a number of streetlights whose coordinates are given by an array of `lights`, each `lights[i] = [position, range]` denoting the streetlight whose coordinates are at `position` and which can illuminate the range `[position - range, position + range]` including the boundary points.
//  
//  When a position `p`, exists that is illuminated by more than one streetlight, this position is a little brighter, now given `lights`, return the **brightest horizontal coordinate position**, and **if more than one position with the same brightness exists, return the one with the smallest coordinates.**
//  
//  Example 1:
//  ```
//  Input:
//  lights = [[-3, 2], [1, 2], [3, 2]]
//  Output:
//  -1
//  Explanation:
//  The first streetlight illuminates the range [-5, -1]
//  The second streetlight illuminates the range [-1, 3]
//  The third streetlight illuminates the range [1, 5]
//  Positions -1, 1, 2, 3 are all illuminated by two streetlights
//  So we return the smallest coordinate, -1
//  ```
//  
//  ![3745.png](https://media-cn.lintcode.com/new_storage_v2/public/202310/a0f462329571446d9c8e00cf8df2014b/3745.png)
//  
//  Example 2:
//  ```
//  Input:
//  lights = [[1, 0], [0, 1]]
//  Output:
//  1
//  ```
//  
//  $1 \leq lights.length \leq 10^5$
//  $lights[i].length == 2$
//  $-10^8 \leq position \leq 10^8$
//  $0 \leq range \leq 10^8$

class Solution {
public:
    /**
     * @param lights: Location and extent of illumination of street lights
     * @return: The brightest position
     */
    int brightestPosition(vector<vector<int>> &lights) {
        // write your code here
        map<int, int> lines;
        for (auto &p: lights) {
            lines[p[0] - p[1]] += 1;
            lines[p[0] + p[1] + 1] -= 1; 
        }

        int prefix = 0;
        int brightest = 0;
        int res = 0;
        for (auto &[pos, val]: lines) {
            prefix += val;
            if (prefix > brightest) {
                brightest = prefix;
                res = pos;
            }
        }
        return res;
    }
};