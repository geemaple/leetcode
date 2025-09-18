#  Tag: Hash Table, Design, Heap (Priority Queue), Ordered Set
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/jB5SE1DpDI4

#  There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.
#  Implement the TaskManager class:
#  
#  
#  TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the given priority.
#  
#  
#  void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to the user with userId. It is guaranteed that taskId does not exist in the system.
#  
#  
#  void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. It is guaranteed that taskId exists in the system.
#  
#  
#  void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that taskId exists in the system.
#  
#  
#  int execTop() executes the task with the highest priority across all users. If there are multiple tasks with the same highest priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the userId associated with the executed task. If no tasks are available, return -1.
#  
#  
#  Note that a user may be assigned multiple tasks.
#   
#  Example 1:
#  
#  Input:
#  ["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
#  [[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]
#  Output:
#  [null, null, null, 3, null, null, 5] 
#  Explanation
#  TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
#  taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
#  taskManager.edit(102, 8); // Updates priority of task 102 to 8.
#  taskManager.execTop(); // return 3. Executes task 103 for User 3.
#  taskManager.rmv(101); // Removes task 101 from the system.
#  taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
#  taskManager.execTop(); // return 5. Executes task 105 for User 5.
#   
#  Constraints:
#  
#  1 <= tasks.length <= 105
#  0 <= userId <= 105
#  0 <= taskId <= 105
#  0 <= priority <= 109
#  0 <= newPriority <= 109
#  At most 2 * 105 calls will be made in total to add, edit, rmv, and execTop methods.
#  The input is generated such that taskId will be valid.
#  
#  

from collections import defaultdict
import heapq
class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.jobs = []
        self.tasks = {}
        self.task_to_user = {}
        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.tasks[taskId] = priority
        self.task_to_user[taskId] = userId
        heapq.heappush(self.jobs, (-priority, -taskId))

    def edit(self, taskId: int, newPriority: int) -> None:
        self.tasks[taskId] = newPriority
        heapq.heappush(self.jobs, (-newPriority, -taskId))

    def rmv(self, taskId: int) -> None:
        del self.tasks[taskId]

    def execTop(self) -> int:
        while len(self.jobs) > 0:
            priority, taskId = heapq.heappop(self.jobs)
            priority = -priority
            taskId = -taskId
            if (taskId not in self.tasks or self.tasks[taskId] != priority):
                continue

            del self.tasks[taskId]
            return self.task_to_user.get(taskId, -1)

        return -1
# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()