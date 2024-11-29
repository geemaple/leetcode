//  Tag: Hash Table, Stack, Design, Ordered Set
//  Time: O(1)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.
//  Implement the FreqStack class:
//  
//  FreqStack() constructs an empty frequency stack.
//  void push(int val) pushes an integer val onto the top of the stack.
//  int pop() removes and returns the most frequent element in the stack.
//  	
//  If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
//  
//  
//  
//   
//  Example 1:
//  
//  Input
//  ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
//  [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
//  Output
//  [null, null, null, null, null, null, null, 5, 7, 5, 4]
//  
//  Explanation
//  FreqStack freqStack = new FreqStack();
//  freqStack.push(5); // The stack is [5]
//  freqStack.push(7); // The stack is [5,7]
//  freqStack.push(5); // The stack is [5,7,5]
//  freqStack.push(7); // The stack is [5,7,5,7]
//  freqStack.push(4); // The stack is [5,7,5,7,4]
//  freqStack.push(5); // The stack is [5,7,5,7,4,5]
//  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
//  freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
//  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
//  freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
//  
//   
//  Constraints:
//  
//  0 <= val <= 109
//  At most 2 * 104 calls will be made to push and pop.
//  It is guaranteed that there will be at least one element in the stack before calling pop.
//  
//  

class FreqStack {
public:
    unordered_map<int, int> frequency;
    unordered_map<int, stack<int>> table;
    int max_freq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        frequency[val] += 1;
        max_freq = max(max_freq, frequency[val]);
        table[frequency[val]].push(val);
    }
    
    int pop() {
        int val = table[max_freq].top();
        table[max_freq].pop();
        frequency[val] -= 1;
        if (table[max_freq].empty()) {
            max_freq -= 1;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

class FreqStack {
public:
    unordered_map<int, int> frequency;
    vector<stack<int>> table;
    FreqStack() {
        
    }
    
    void push(int val) {
        frequency[val] += 1;
        int freq = frequency[val];
        if (freq > table.size()) {
            table.push_back(stack<int>());
        } 
            
        table[freq - 1].push(val);
    }
    
    int pop() {
        stack<int> &last = table.back();
        int val = last.top();
        last.pop();
        if (last.size() == 0) {
            table.pop_back();
        }

        frequency[val] -= 1;
        if (frequency[val] == 0) {
            frequency.erase(val);
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> q;
    unordered_map<int, int> freq;
    int pos = 0;
    FreqStack() {
        
    }
    void push(int x) {
        q.emplace(++freq[x], make_pair(++pos, x));
    }
    
    int pop() {
        auto val = q.top();
        q.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */