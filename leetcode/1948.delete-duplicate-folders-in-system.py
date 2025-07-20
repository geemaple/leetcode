#  Tag: Array, Hash Table, String, Trie, Hash Function
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/ujkUy2RrY0I

#  Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
#  
#  For example, ["one", "two", "three"] represents the path "/one/two/three".
#  
#  Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
#  
#  For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
#  
#  	
#  /a
#  /a/x
#  /a/x/y
#  /a/z
#  /b
#  /b/x
#  /b/x/y
#  /b/z
#  
#  
#  However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
#  
#  Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
#  Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.
#   
#  Example 1:
#  
#  
#  Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
#  Output: [["d"],["d","a"]]
#  Explanation: The file structure is as shown.
#  Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
#  folder named "b".
#  
#  Example 2:
#  
#  
#  Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
#  Output: [["c"],["c","b"],["a"],["a","b"]]
#  Explanation: The file structure is as shown. 
#  Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because they both contain an empty folder named "y".
#  Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted because they were not marked beforehand.
#  
#  Example 3:
#  
#  
#  Input: paths = [["a","b"],["c","d"],["c"],["a"]]
#  Output: [["c"],["c","d"],["a"],["a","b"]]
#  Explanation: All folders are unique in the file system.
#  Note that the returned array can be in a different order as the order does not matter.
#  
#   
#  Constraints:
#  
#  1 <= paths.length <= 2 * 104
#  1 <= paths[i].length <= 500
#  1 <= paths[i][j].length <= 10
#  1 <= sum(paths[i][j].length) <= 2 * 105
#  path[i][j] consists of lowercase English letters.
#  No two paths lead to the same folder.
#  For any folder not at the root level, its parent folder will also be in the input.
#  
#  

from collections import defaultdict
class Node:
    def __init__(self, name: str):
        self.name = name
        self.deleted = False
        self.children = {}

class Trie:
    def __init__(self):
        self.root = Node('/')
        self.pattern = defaultdict(list)

    def build(self, path: list):
        node = self.root
        for c in path:
            if c not in node.children:
                node.children[c] = Node(c)
            node = node.children[c]

    def serialize(self, node: Node) -> str:
        key = '('       
        for c, child in node.children.items():
            key += c + self.serialize(child)
        key += ')'

        if key != '()':
            self.pattern[key].append(node)

        return key

    def mark_delete(self):
        for nodes in self.pattern.values():
            if len(nodes) >= 2:
                for node in nodes:
                    node.deleted = True

    def trim(self, node: Node, path: list, res: list):
        for c, child in node.children.items():
            if not child.deleted:
                self.trim(child, path + [c], res)
            
        if len(path) > 0:
            res.append(list(path))


class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        trie = Trie()

        # Sort paths because dict insertion order affects iteration
        for path in sorted(paths): 
            trie.build(path)

        trie.serialize(trie.root)
        trie.mark_delete()
        
        res = []
        trie.trim(trie.root, [], res)
        return res