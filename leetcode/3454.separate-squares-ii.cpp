//  Tag: Array, Binary Search, Segment Tree, Line Sweep
//  Time: O(N^2logN)
//  Space: O(N)
//  Ref: -
//  Note: Seg-Tree

//  You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
//  Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
//  Answers within 10-5 of the actual answer will be accepted.
//  Note: Squares may overlap. Overlapping areas should be counted only once in this version.
//   
//  Example 1:
//  
//  Input: squares = [[0,0,1],[2,2,1]]
//  Output: 1.00000
//  Explanation:
//  
//  Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
//  
//  Example 2:
//  
//  Input: squares = [[0,0,2],[1,1,1]]
//  Output: 1.00000
//  Explanation:
//  
//  Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
//  
//   
//  Constraints:
//  
//  1 <= squares.length <= 5 * 104
//  squares[i] = [xi, yi, li]
//  squares[i].length == 3
//  0 <= xi, yi <= 109
//  1 <= li <= 109
//  The total area of all the squares will not exceed 1015.
//  
//  

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> lines;
        for (const auto& square : squares) {
            int x = square[0], y = square[1], l = square[2];
            lines.emplace_back(y, 1, x, x + l);
            lines.emplace_back(y + l, -1, x, x + l);
        }

        sort(lines.begin(), lines.end());

        vector<pair<int,int>> window;
        int prev_y = get<0>(lines[0]);
        double total = 0;
        vector<tuple<int, int, double>> areas; // y, height, width

        for (const auto& line : lines) {
            int y, event, x1, x2;
            tie(y, event, x1, x2) = line;

            if (y > prev_y && !window.empty()) {
                int h = y - prev_y;
                double w = union_len(window);
                areas.emplace_back(prev_y, h, w);
                total += h * w;
            }

            if (event == 1) {
                window.emplace_back(x1, x2);
            } else {
                auto it = find(window.begin(), window.end(), make_pair(x1, x2));
                if (it != window.end()) {
                    window.erase(it);
                }
            }

            prev_y = y;
        }

        double half = total / 2.0;
        double acc = 0;
        for (const auto& area : areas) {
            int y, h;
            double w;
            tie(y, h, w) = area;
            if (acc + h * w >= half) {
                return y + (half - acc) / w;
            }
            acc += h * w;
        }

        return 0.0;
    }

    double union_len(vector<pair<int,int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        double res = 0;
        int end = INT_MIN;

        for (const auto& interval : intervals) {
            int a = interval.first;
            int b = interval.second;
            if (a > end) {
                res += b - a;
                end = b;
            } else if (b > end) {
                res += b - end;
                end = b;
            }
        }
        return res;
    }
};