class MovingAverage {

private:
    vector<int> presum;
    int size;
    int id;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : presum(size + 1, 0) {
        this->id = 0;
        this->size = size;
    }
    
    int mode(int index)
    {
        return index % (size + 1);
    }

    double next(int val) {
        id++;
        presum[mode(id)] = (presum[mode(id - 1)] + val);
        if (id <= size)
        {
            return double(presum[mode(id)]) / id;
        }
        else
        {
            return double(presum[mode(id)] - presum[mode(id - size)]) / size;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
