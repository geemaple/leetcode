//  Tag: Array, Hash Table, Sorting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
//  A building is covered if there is at least one building in all four directions: left, right, above, and below.
//  Return the number of covered buildings.
//   
//  Example 1:
//  
//  
//  Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
//  Output: 1
//  Explanation:
//  
//  Only building [2,2] is covered as it has at least one building:
//  
//  	
//  above ([1,2])
//  below ([3,2])
//  left ([2,1])
//  right ([2,3])
//  
//  
//  Thus, the count of covered buildings is 1.
//  
//  
//  Example 2:
//  
//  
//  Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
//  Output: 0
//  Explanation:
//  
//  No building has at least one building in all four directions.
//  
//  
//  Example 3:
//  
//  
//  Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
//  Output: 1
//  Explanation:
//  
//  Only building [3,3] is covered as it has at least one building:
//  
//  	
//  above ([1,3])
//  below ([5,3])
//  left ([3,2])
//  right ([3,5])
//  
//  
//  Thus, the count of covered buildings is 1.
//  
//  
//   
//  Constraints:
//  
//  2 <= n <= 105
//  1 <= buildings.length <= 105 
//  buildings[i] = [x, y]
//  1 <= x, y <= n
//  All coordinates of buildings are unique.
//  
//  

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> xcoord, ycoord;
        for (auto &p: buildings) {
            if (xcoord.find(p[0]) == xcoord.end()) {
                xcoord[p[0]] = {p[1], p[1]};
            } else {
                xcoord[p[0]] = {min(xcoord[p[0]].first, p[1]), max(xcoord[p[0]].second, p[1])};
            }

            if (ycoord.find(p[1]) == ycoord.end()) {
                ycoord[p[1]] = {p[0], p[0]};
            } else {
                ycoord[p[1]] = {min(ycoord[p[1]].first, p[0]), max(ycoord[p[1]].second, p[0])};
            }
        }

        int res = 0;
        for (auto &p: buildings) {
            if (xcoord.find(p[0]) != xcoord.end() && p[1] > xcoord[p[0]].first && p[1] < xcoord[p[0]].second) {
                if (ycoord.find(p[1]) != ycoord.end() && p[0] > ycoord[p[1]].first && p[0] < ycoord[p[1]].second) {
                    res += 1;
                }
            }
        }
        return res;
    }
};