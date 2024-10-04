//  Tag: Stack
//  Time: -
//  Space: O(N)
//  Ref: Leetcode-716
//  Note: -

//  Design a max stack that supports push, pop, top, peekMax and popMax.
//  
//  1.
//  push(x) -- Push element x onto stack.
//  2.
//  pop() -- Remove the element on top of the stack and return it.
//  3.
//  top() -- Get the element on the top.
//  4.
//  peekMax() -- Retrieve the maximum element in the stack.
//  5.
//  popMax() -- Retrieve the maximum element in the stack, and remove it.
//  If you find more than one maximum elements, only remove the top-most one.
//  
//  ---
//  *
//  
//  ```
//  Input:
//  push(5)
//  push(1)
//  push(5)
//  top()
//  popMax()
//  top()
//  peekMax()
//  pop()
//  top()
//  Output:
//  5
//  5
//  1
//  5
//  1
//  5
//  ```
//  
//  1. `-1e7 <= x <= 1e7`
//  2. Number of operations won't exceed `10000`.
//  3. The last four operations won't be called when stack is empty.

class MaxStack {
public:
    stack<int> st;
    stack<int> max_st;
    MaxStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        int max_val = max_st.empty() ? number : max_st.top();
        st.push(number);
        max_st.push(max_val > number ? max_val : number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int val = top();
        st.pop();
        max_st.pop();
        return val;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        return st.top();
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        // write your code here
        return max_st.top();
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        // write your code here
        int max_val = peekMax();
        stack<int> tmp;
        while (top() != max_val) {
            tmp.push(top());
            pop();
        }

        pop();

        while (!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }

        return max_val;
    }
};


#include <list>
class MaxStack {
public:
    list<int> st;
    map<int, vector<list<int>::iterator>> hash;
    MaxStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        st.push_back(number);
        hash[number].push_back(prev(st.end()));
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int val = st.back();
        st.pop_back();
        hash[val].pop_back();
        if (hash[val].empty()) {
            hash.erase(val);
        }
        return val;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        return st.back();
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        // write your code here
        return prev(hash.end())->first;
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        // write your code here
        auto it = prev(hash.end());
        int val = it->first;

        auto last = it->second.back();
        st.erase(last);

        it->second.pop_back();
        if (it->second.empty()) {
            hash.erase(it);
        }
        return val;
    }
};