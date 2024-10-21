//  Tag: Iterator
//  Time: O(*1)
//  Space: O(N)
//  Ref: Leetcode-251
//  Note: -

//  Design an iterator to realize the function of flattening two-dimensional vector.
//  
//  Example 1:
//  ```
//  Input:[[1,2],[3],[4,5,6]]
//  Output:[1,2,3,4,5,6]
//  ```
//  Example 2:
//  ```
//  Input:[[7,9],[5]]
//  Output:[7,9,5]
//  ```
//  
//  

class Vector2D {
public:
    stack<vector<int>> st;
    stack<int> res;
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        for (int i = vec2d.size() - 1; i >=0; i--) {
            st.push(vec2d[i]);
        }
    }

    int next() {
        // Write your code here
        int top = res.top();
        res.pop();
        return top;
    }

    bool hasNext() {
        // Write your code here
        while (!st.empty() && res.empty()) {
            vector<int> cur = st.top();
            st.pop();
            for (int i = cur.size() - 1; i >= 0; i--) {
                res.push(cur[i]);
            }
        }

        return !res.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */