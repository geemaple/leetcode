class MovingAverage {
private:
    deque<int> dq;
    int size;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
    }
    
    double next(int val) {
        
        dq.push_back(val);
        sum += val;
        
        if (dq.size() > size)
        {
            sum -= dq.front();
            dq.pop_front();
        }
        
        return double(sum) / dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */