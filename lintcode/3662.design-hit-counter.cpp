//  Tag: Simulation
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-362
//  Note: -

//  In this question, you need to design a HitCounter class.
//  
//  In this class, there are the following functions:
//  
//  - `HitCounter()`: No-argument constructor
//  - `void hit(int timestamp)`: Indicates that a tap occurs at the specified time
//  - `int getHits(int timestamp)`: Returns the total number of hits within 300 seconds before the specified time
//  
//  Where `timestamp` is in seconds.
//  
//  **Example 1**
//  
//  Input:
//  
//  ```plaintext
//  ["hit(1)", "hit(2)", "hit(3)", "getHits(3)", "hit(301)", "getHits(301)"]
//  ```
//  
//  Output:
//  
//  ```plaintext
//  [null, null, null, 3, null, 3]
//  ```
//  
//  **Example 2**
//  
//  Input:
//  
//  ```plaintext
//  ["hit(1)", "hit(1)", "hit(1)", "getHits(2)"]
//  ```
//  
//  Output:
//  
//  ```plaintext
//  [null, null, null, 3]
//  ```
//  
//  You can assume that when the system calls the `void hit(int timestamp)` and `int getHits(int timestamp)` methods, it must be called in chronological order, that is, the smaller `timestamp` is called first.
//  
//  There may be multiple hits at the same time.
//  
//  Hit action takes negligible time.
//  
//  At the same moment (`timestamp`), `getHits()` will not happen before `hit()`.

class HitCounter {
public:
    queue<int> q;
    HitCounter() {
        
    }

    /**
     * @param timestamp: the timestamp
     * @return: nothing
     */
    void hit(int timestamp) {
        q.push(timestamp);
    }

    /**
     * @param timestamp: the timestamp
     * @return: the count of hits in recent 300 seconds
     */
    int getHits(int timestamp) {
        while (!q.empty() && q.front() <= timestamp - 300) {
            q.pop();
        }
        return q.size();
    }
};