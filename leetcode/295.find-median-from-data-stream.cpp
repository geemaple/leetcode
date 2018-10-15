class MedianFinder {
    
private:
    priority_queue<int, vector<int>, less<int>> leftHeap; // big heap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // small heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (leftHeap.size() <= rightHeap.size())
        {
            leftHeap.push(num);
        }
        else
        {
            rightHeap.push(num);
        }
        
        if (rightHeap.size() > 0 && leftHeap.top() > rightHeap.top()) {
            int left = leftHeap.top();
            leftHeap.pop();
            
            int right = rightHeap.top();
            rightHeap.pop();
            
            leftHeap.push(right);
            rightHeap.push(left);
        }
    }
    
    double findMedian() {
        if (leftHeap.size() > rightHeap.size())
        {
            return leftHeap.top();
        }
        else
        {
            double sum = leftHeap.top() + rightHeap.top();
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