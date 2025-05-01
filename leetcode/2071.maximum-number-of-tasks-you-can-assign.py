#  Tag: Array, Binary Search, Greedy, Queue, Sorting, Monotonic Queue
#  Time: O(NLogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/qvKodnc1_Dg

#  You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
#  Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.
#  Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.
#   
#  Example 1:
#  
#  Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
#  Output: 3
#  Explanation:
#  We can assign the magical pill and tasks as follows:
#  - Give the magical pill to worker 0.
#  - Assign worker 0 to task 2 (0 + 1 >= 1)
#  - Assign worker 1 to task 1 (3 >= 2)
#  - Assign worker 2 to task 0 (3 >= 3)
#  
#  Example 2:
#  
#  Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
#  Output: 1
#  Explanation:
#  We can assign the magical pill and tasks as follows:
#  - Give the magical pill to worker 0.
#  - Assign worker 0 to task 0 (0 + 5 >= 5)
#  
#  Example 3:
#  
#  Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
#  Output: 2
#  Explanation:
#  We can assign the magical pills and tasks as follows:
#  - Give the magical pill to worker 0 and worker 1.
#  - Assign worker 0 to task 0 (0 + 10 >= 10)
#  - Assign worker 1 to task 1 (10 + 10 >= 15)
#  The last pill is not given because it will not make any worker strong enough for the last task.
#  
#   
#  Constraints:
#  
#  n == tasks.length
#  m == workers.length
#  1 <= n, m <= 5 * 104
#  0 <= pills <= m
#  0 <= tasks[i], workers[j], strength <= 109
#  
#  

from collections import deque
class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks.sort()
        workers.sort()
        l = 0
        r = min(len(tasks), len(workers))
        while l < r:
            mid = l + (r - l + 1) // 2
            if self.fit(tasks, workers, pills, strength, mid):
                l = mid
            else:
                r = mid - 1
        return l

    def fit(self, tasks: list, workers: list, pills: int, strength: int, k: int) -> bool:
        n = len(workers)
        q = deque()
        i = 0
        for j in range(n - k, n):
            while i < k and tasks[i] <= workers[j] + strength:
                q.append(tasks[i])
                i += 1

            if len(q) == 0:
                return False

            if q[0] <= workers[j]:
                q.popleft()
            elif pills > 0:
                pills -= 1
                q.pop()
            else:
                return False

        return True

from sortedcontainers import SortedList
class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks.sort()
        workers.sort()
        l = 0
        r = min(len(tasks), len(workers))
        while l < r:
            mid = l + (r - l + 1) // 2
            if self.fit(tasks, workers, pills, strength, mid):
                l = mid
            else:
                r = mid - 1
        return l

    def fit(self, tasks: list, workers: list, pills: int, strength: int, k: int) -> bool:

        workers = SortedList(workers[-k:])
        for i in range(k - 1, -1, -1):
            if workers[-1] >= tasks[i]:
                workers.pop(-1)
                continue
            
            j = workers.bisect_left(tasks[i] - strength)
            if pills > 0 and j < len(workers):
                workers.pop(j)
                pills -= 1
            else:
                return False

        return True