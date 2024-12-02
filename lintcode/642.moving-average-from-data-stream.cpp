//  Tag: Data Stream, Sliding Window, Queue
//  Time: O(1)
//  Space: O(K)
//  Ref: Leetcode-346
//  Note: -

//  Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//  
//  **Example 1:**
//  ```
//  MovingAverage m = new MovingAverage(3);
//  m.next(1) = 1 // return 1.00000
//  m.next(10) = (1 + 10) / 2 // return 5.50000
//  m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
//  m.next(5) = (10 + 3 + 5) / 3 // return 6.00000
//  ```
//  
//  

class MovingAverage {
public:
    /*
    * @param size: An integer
    */
    queue<int> q;
    int size;
    long long total;
    MovingAverage(int size): size(size), total(0) {
        // do intialization if necessary
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        q.push(val);
        total += val;
        if (q.size() > size) {
            int cur = q.front();
            q.pop();
            total -= cur;
        }

        return double(total) / min(size, int(q.size()));
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */