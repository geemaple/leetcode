//  Tag: Array, Graph, Heap (Priority Queue), Matrix, Shortest Path
//  Time: O(NMlog(NM))
//  Space: O(NM)
//  Ref: -
//  Note: -

//  There is a dungeon with n x m rooms arranged as a grid.
//  You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
//  Return the minimum time to reach the room (n - 1, m - 1).
//  Two rooms are adjacent if they share a common wall, either horizontally or vertically.
//   
//  Example 1:
//  
//  Input: moveTime = [[0,4],[4,4]]
//  Output: 7
//  Explanation:
//  The minimum time required is 7 seconds.
//  
//  At time t == 4, move from room (0, 0) to room (1, 0) in one second.
//  At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
//  
//  
//  Example 2:
//  
//  Input: moveTime = [[0,0,0,0],[0,0,0,0]]
//  Output: 6
//  Explanation:
//  The minimum time required is 6 seconds.
//  
//  At time t == 0, move from room (0, 0) to room (1, 0) in one second.
//  At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
//  At time t == 3, move from room (1, 1) to room (1, 2) in one second.
//  At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
//  
//  
//  Example 3:
//  
//  Input: moveTime = [[0,1],[1,2]]
//  Output: 4
//  
//   
//  Constraints:
//  
//  2 <= n == moveTime.length <= 750
//  2 <= m == moveTime[i].length <= 750
//  0 <= moveTime[i][j] <= 109
//  
//  

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        using state = tuple<int, int, int, int>;
        int n = moveTime.size();
        int m = moveTime[0].size();

        int directions[5] = {-1, 0, 1, 0, -1};
        priority_queue<state, vector<state>, greater<state>> heap;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        heap.emplace(0, 0, 0, 0);

        while (!heap.empty()) {
            auto [cost, i, j, delta] = heap.top();
            heap.pop();
            if (visited[i][j]) {
                continue;
            }          
            visited[i][j] = true;
            if (i == n - 1 && j == m - 1) {
                return cost;
            }

            for (int d = 0; d < 4; d++) {
                int x = i + directions[d];
                int y = j + directions[d + 1];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    int next_cost = max(cost, moveTime[x][y]) + delta + 1;
                    heap.emplace(next_cost, x, y, 1 - delta);
                }
            }
        }


        return -1;
    }
};