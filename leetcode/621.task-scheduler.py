#  Tag: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
#  Return the minimum number of CPU intervals required to complete all tasks.
#   
#  Example 1:
#  
#  Input: tasks = ["A","A","A","B","B","B"], n = 2
#  Output: 8
#  Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
#  After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
#  
#  Example 2:
#  
#  Input: tasks = ["A","C","A","B","D","B"], n = 1
#  Output: 6
#  Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
#  With a cooling interval of 1, you can repeat a task after just one other task.
#  
#  Example 3:
#  
#  Input: tasks = ["A","A","A", "B","B","B"], n = 3
#  Output: 10
#  Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
#  There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
#  
#   
#  Constraints:
#  
#  1 <= tasks.length <= 104
#  tasks[i] is an uppercase English letter.
#  0 <= n <= 100
#  
#  

from collections import Counter
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        task_counts = Counter(tasks)
        max_count = max(task_counts.values())
        tasks_with_max_count = list(task_counts.values()).count(max_count)

        part_count = max_count - 1
        part_length = n + 1
        empty_slots = part_count * part_length
        total_slots = empty_slots + tasks_with_max_count
        
        return max(len(tasks), total_slots)

import heapq
from collections import Counter
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        heap = []
        counter = Counter(tasks)
        for task, count in counter.items():
            heapq.heappush(heap, (-count, task))

        res = 0
        while len(heap) > 0:
            visited = {}
            for i in range(n + 1):
                if len(heap) == 0:
                    break

                top = heapq.heappop(heap)
                count, task = -top[0], top[1]
                visited[task] = count

            for task, count in visited.items():
                if count > 1:
                    heapq.heappush(heap, (-(count - 1), task))

            res += len(visited) if len(heap) == 0 else n + 1

        return res
