class MinStack {
private:
    stack<int> minstack;
    stack<int> container;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        container.push(x);
        int cur_min = x;
        if (minstack.size() > 0)
        {
            cur_min = min(cur_min, minstack.top());
        }
        minstack.push(cur_min);
    }
    
    void pop() {
        container.pop();
        minstack.pop();
    }
    
    int top() {
        return container.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */