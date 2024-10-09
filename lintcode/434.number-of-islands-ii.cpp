//  Tag: Union Find
//  Time: O(K)
//  Space: O(NM + K)
//  Ref: -
//  Note: Leetcode-305

//  Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k).
//  Originally, the 2D matrix is all 0 which means there is only sea in the matrix.
//  The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island.
//  Return how many island are there in the matrix after each operator.You need to return an array of size K.
//  
//  **Example 1:**
//  
//  ```
//  Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
//  Output: [1,1,2,2]
//  Explanation:
//  0.  00000
//      00000
//      00000
//      00000
//  1.  00000
//      01000
//      00000
//      00000
//  2.  01000
//      01000
//      00000
//      00000
//  3.  01000
//      01000
//      00000
//      00010
//  4.  01000
//      01000
//      00000
//      00011
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
//  Output: [1,1,2,2]
//  ```
//  
//  0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class UnionFind {
public:
    vector<int> table;
    UnionFind(int n): table(n) {
        for (int i = 0; i < n; i++) {
            table[i] = i;
        }
    }

    int find(int a) {
        if (a == table[a]) {
            return a;
        }
        table[a] = find(table[a]);
        return table[a];
    }

    bool connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            table[root_a] = root_b;
            return true;
        }
        return false;
    }

};

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        UnionFind uf(n * m);
        unordered_set<int> islands;
        vector<int> res;
        int directions[] = {-1, 0, 1, 0, -1};
        int count = 0;
        
        for (auto p: operators) {
            int i = p.x;
            int j = p.y;
            islands.insert(i * m + j);
            
            for (int d = 0; d < 4; d++) {
                int x = i + directions[d];
                int y = j + directions[d + 1];

                if (x >= 0 && x < n && y >= 0 && y < m && islands.count(x * m + y) > 0) {
                    if (uf.connect(i * m + j, x * m + y)) {
                        count += 1;
                    }
                }
            }
            res.push_back(islands.size() - count);
        }
        return res;
    }
};