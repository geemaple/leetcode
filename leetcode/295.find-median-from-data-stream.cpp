class MedianFinder {
    
private:
    priority_queue<int, vector<int>, less<int>> lo; // big heap
    priority_queue<int, vector<int>, greater<int>> hi; // small heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if (lo.size() > hi.size())
        {
            return lo.top();
        }
        else
        {
            double sum = lo.top() + hi.top();
            return sum / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */