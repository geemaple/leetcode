//  Tag: Binary Search on Answer, Binary Search
//  Time: O(N * logM + M * logN)
//  Space: O(1)
//  Ref: Leetcode-302
//  Note: Graph

//  An image is represented by a binary matrix with `0` as a white pixel and `1` as a black pixel.
//  The black pixels are connected, i.e., there is only one black region.
//  Pixels are connected horizontally and vertically.
//  Given the location `(x, y)` of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
//  
//  ---
//  
//  **Example 1:**
//  ```
//  Input：["0010","0110","0100"]，x=0，y=2
//  Output：6
//  Explanation：
//  The upper left coordinate of the matrix is (0,1), and the lower right coordinate is (2,2).
//  ```
//  
//  **Example 2:**
//  ```
//  Input：["1110","1100","0000","0000"], x = 0, y = 1
//  Output：6
//  Explanation：
//  The upper left coordinate of the matrix is (0, 0), and the lower right coordinate is (1,2).
//  ```
//  
//  

class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int n = image.size();
        int m = image[0].size();

        int left = search(image, 0, y, checkCol, false);
        int right = search(image, y, m, checkCol, true);
        int top = search(image, 0, x, checkRow, false);
        int bottom = search(image, x, n, checkRow, true);  
        return (right - left) * (bottom - top);
    }

    static bool checkRow(vector<vector<char>> &image, int row, bool oppsite) {
        bool isIsland = false;
        for (auto &point : image[row]) {
            if (point == '1') {
                isIsland = true;
                break;
            }
        }
        return oppsite ? !isIsland : isIsland;
    }

    static bool checkCol(vector<vector<char>> &image, int col, bool oppsite) {
        bool isIsland = false;
        for (auto &row : image) {
            if (row[col] == '1') {
                isIsland = true;
                break;
            }
        }
        return oppsite ? !isIsland : isIsland;
    }

    int search(vector<vector<char>> &image, int start, int end, bool (*check)(vector<vector<char>> &, int, bool), bool opposite) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (check(image, mid, opposite)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int n = image.size();
        int m = image[0].size();

        int left = 0, right = y;
        while (left < right) {
            int mid = (left + right) / 2;
            bool hasBlackPixel = false;
            for (int i = 0; i < n; i++) {
                if (image[i][mid] == '1') {
                    hasBlackPixel = true;
                    break;
                }
            }
            if (hasBlackPixel) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int left_most = left;

        left = y;
        right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            bool hasBlackPixel = false;
            for (int i = 0; i < n; i++) {
                if (image[i][mid] == '1') {
                    hasBlackPixel = true;
                    break;
                }
            }
            if (hasBlackPixel) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int right_most = left;

        int top = 0, bottom = x;
        while (top < bottom) {
            int mid = (top + bottom) / 2;
            bool hasBlackPixel = false;
            for (int j = left_most; j <= right_most; j++) {
                if (image[mid][j] == '1') {
                    hasBlackPixel = true;
                    break;
                }
            }
            if (hasBlackPixel) {
                bottom = mid;
            } else {
                top = mid + 1;
            }
        }
        int top_most = top;

        top = x;
        bottom = n - 1;
        while (top < bottom) {
            int mid = (top + bottom + 1) / 2;
            bool hasBlackPixel = false;
            for (int j = left_most; j <= right_most; j++) {
                if (image[mid][j] == '1') {
                    hasBlackPixel = true;
                    break;
                }
            }
            if (hasBlackPixel) {
                top = mid;
            } else {
                bottom = mid - 1;
            }
        }
        int bottom_most = top;

        int width = right_most - left_most + 1;
        int height = bottom_most - top_most + 1;
        return width * height;
    }
};