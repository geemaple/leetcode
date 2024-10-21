//  Tag: Simulation
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a list, each element in the list can be a list or an integer.Flatten it into a simply list with integers.
//  
//  **Example 1:**  
//   
//  Input:  
//  ``` 
//  list = [[1,1],2,[1,1]]
//  ``` 
//  Output:  
//  ``` 
//  [1,1,2,1,1]
//  ``` 
//  Explanation:  
//  
//  Flatten it into a simply list with integers.
//  
//  **Example 2:**  
//   
//  Input:  
//  ``` 
//  list = [1,2,[1,2]]
//  ``` 
//  Output:  
//  ``` 
//  [1,2,1,2]
//  ``` 
//  Explanation:  
//  
//  Flatten it into a simply list with integers.
//  
//  **Example 3:**  
//   
//  Input:  
//  ``` 
//  list = [4,[3,[2,[1]]]]
//  ``` 
//  Output:  
//  ``` 
//  [4,3,2,1]
//  ``` 
//  Explanation:  
//  
//  Flatten it into a simply list with integers.
//  
//  If the element in the given list is a list, it can contain list too.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> res;
        flatten(nestedList, res);
        return res;
    }

    void flatten(const vector<NestedInteger> &nestedList, vector<int>& result) {
        for (auto x : nestedList) {
            if (x.isInteger()) {
                result.push_back(x.getInteger());
            } else {
                flatten(x.getList(), result);
            }
        }
    }
};

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> result;
        stack<NestedInteger> st;

        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }

        while (!st.empty()) {
            NestedInteger cur = st.top();
            st.pop();

            if (cur.isInteger()) {
                result.push_back(cur.getInteger());
            } else {
                auto &list = cur.getList();
                for (int i = list.size() - 1; i >= 0; i--) {
                    st.push(list[i]);
                }
            }
        }

        return result;
    }
};