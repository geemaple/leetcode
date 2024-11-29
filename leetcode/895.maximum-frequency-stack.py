#  Tag: Hash Table, Stack, Design, Ordered Set
#  Time: O(1)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.
#  Implement the FreqStack class:
#  
#  FreqStack() constructs an empty frequency stack.
#  void push(int val) pushes an integer val onto the top of the stack.
#  int pop() removes and returns the most frequent element in the stack.
#  	
#  If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
#  
#  
#  
#   
#  Example 1:
#  
#  Input
#  ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
#  [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
#  Output
#  [null, null, null, null, null, null, null, 5, 7, 5, 4]
#  
#  Explanation
#  FreqStack freqStack = new FreqStack();
#  freqStack.push(5); // The stack is [5]
#  freqStack.push(7); // The stack is [5,7]
#  freqStack.push(5); // The stack is [5,7,5]
#  freqStack.push(7); // The stack is [5,7,5,7]
#  freqStack.push(4); // The stack is [5,7,5,7,4]
#  freqStack.push(5); // The stack is [5,7,5,7,4,5]
#  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
#  freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
#  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
#  freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
#  
#   
#  Constraints:
#  
#  0 <= val <= 109
#  At most 2 * 104 calls will be made to push and pop.
#  It is guaranteed that there will be at least one element in the stack before calling pop.
#  
#  

from collections import defaultdict
class FreqStack:

    def __init__(self):
        self.frequency = defaultdict(int)
        self.table = defaultdict(list)
        self.max_freq = 0

    def push(self, val: int) -> None:
        self.frequency[val] += 1
        freq = self.frequency[val]
        self.max_freq = max(self.max_freq, freq)
        self.table[freq].append(val)

    def pop(self) -> int:
        val = self.table[self.max_freq].pop()
        self.frequency[val] -= 1
        if len(self.table[self.max_freq]) == 0:
            self.max_freq -= 1

        return val

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()

class FreqStack:

    def __init__(self):
        self.frequency = {}
        self.table = []

    def push(self, val: int) -> None:
        if val not in self.frequency:
            self.frequency[val] = 0

        self.frequency[val] += 1
        freq = self.frequency[val]

        if freq > len(self.table):
            self.table.append([val])
        else:
            self.table[freq - 1].append(val)

    def pop(self) -> int:
        last = self.table[-1]
        val = last.pop()
        if len(last) == 0:
            self.table.pop()

        self.frequency[val] -= 1
        if self.frequency[val] == 0:
            del self.frequency[val]

        return val

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()

from collections import defaultdict
import heapq
class FreqStack:

    def __init__(self):
        self.heap = []
        self.frequency = defaultdict(int)
        self.pos = 0

    def push(self, val: int) -> None:
        self.frequency[val] += 1
        self.pos += 1
        heapq.heappush(self.heap, (-self.frequency[val], -self.pos, val))

    def pop(self) -> int:
        cur = heapq.heappop(self.heap)
        val = cur[2]
        self.frequency[val] -= 1
        return val

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()