#  Tag: Hash Table, Tree, Depth-First Search, Breadth-First Search, Design, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/1Npf6eFaYRQ

#  Given a binary tree with the following rules:
#  
#  root.val == 0
#  For any treeNode:
#  	
#  If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
#  If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
#  
#  
#  
#  Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
#  Implement the FindElements class:
#  
#  FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
#  bool find(int target) Returns true if the target value exists in the recovered binary tree.
#  
#   
#  Example 1:
#  
#  
#  Input
#  ["FindElements","find","find"]
#  [[[-1,null,-1]],[1],[2]]
#  Output
#  [null,false,true]
#  Explanation
#  FindElements findElements = new FindElements([-1,null,-1]); 
#  findElements.find(1); // return False 
#  findElements.find(2); // return True 
#  Example 2:
#  
#  
#  Input
#  ["FindElements","find","find","find"]
#  [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
#  Output
#  [null,true,true,false]
#  Explanation
#  FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
#  findElements.find(1); // return True
#  findElements.find(3); // return True
#  findElements.find(5); // return False
#  Example 3:
#  
#  
#  Input
#  ["FindElements","find","find","find","find"]
#  [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
#  Output
#  [null,true,false,false,true]
#  Explanation
#  FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
#  findElements.find(2); // return True
#  findElements.find(3); // return False
#  findElements.find(4); // return False
#  findElements.find(5); // return True
#  
#   
#  Constraints:
#  
#  TreeNode.val == -1
#  The height of the binary tree is less than or equal to 20
#  The total number of nodes is between [1, 104]
#  Total calls of find() is between [1, 104]
#  0 <= target <= 106
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        root.val = 0
        q = deque([root])
        self.visited = set()
        while len(q) > 0:
            cur = q.popleft()
            self.visited.add(cur.val)
            if cur.left:
                cur.left.val = cur.val * 2 + 1
                q.append(cur.left)
            
            if cur.right:
                cur.right.val = cur.val * 2 + 2
                q.append(cur.right)

    def find(self, target: int) -> bool:
        return target in self.visited

class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root

    def find(self, target: int) -> bool:
        node = self.root
        bin_str = bin(target+1)[3:]
        for bit in bin_str:
            if node is not None:
                node = (node.left, node.right)[int(bit)]
            else:
                return False
        return bool(node)

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)