#  Tag: Stack, Design
#  Time: O(1)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
#  Implement the MinStack class:
#  
#  MinStack() initializes the stack object.
#  void push(int val) pushes the element val onto the stack.
#  void pop() removes the element on the top of the stack.
#  int top() gets the top element of the stack.
#  int getMin() retrieves the minimum element in the stack.
#  
#  You must implement a solution with O(1) time complexity for each function.
#   
#  Example 1:
#  
#  Input
#  ["MinStack","push","push","push","getMin","pop","top","getMin"]
#  [[],[-2],[0],[-3],[],[],[],[]]
#  
#  Output
#  [null,null,null,null,-3,null,0,-2]
#  
#  Explanation
#  MinStack minStack = new MinStack();
#  minStack.push(-2);
#  minStack.push(0);
#  minStack.push(-3);
#  minStack.getMin(); // return -3
#  minStack.pop();
#  minStack.top();    // return 0
#  minStack.getMin(); // return -2
#  
#   
#  Constraints:
#  
#  -231 <= val <= 231 - 1
#  Methods pop, top and getMin operations will always be called on non-empty stacks.
#  At most 3 * 104 calls will be made to push, pop, top, and getMin.
#  
#  

class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        cur_small = float('inf') if len(self.stack) == 0 else self.getMin()
        self.stack.append((val, min(val, cur_small)))

    def pop(self) -> None:
        self.stack.pop()
        
    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]

class MinStack:

    def __init__(self):
        self.stack = []
        self.mini = []

    def push(self, val: int) -> None:
        cur_small = float('inf') if len(self.stack) == 0 else self.getMin()
        self.mini.append(min(val, cur_small))
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.mini.pop()
        
    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.mini[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()