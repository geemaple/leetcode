#  Tag: Array, Backtracking, Bitmask
#  Time: O(N!)
#  Space: O(N)
#  Ref: -
#  Note: -

#  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
#  Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
#  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
#   
#  Example 1:
#  
#  
#  Input: n = 4
#  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
#  Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
#  
#  Example 2:
#  
#  Input: n = 1
#  Output: [["Q"]]
#  
#   
#  Constraints:
#  
#  1 <= n <= 9
#  
#  

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:

        res = []
        tmp = [["." for i in range(n)] for j in range(n)]
        vertical = set()
        diagonal_pus = set()
        diagonal_minus = set()

        self.dfs(n, tmp, res, 0, vertical, diagonal_pus, diagonal_minus)

        return res

        
    def dfs(self, n: int, tmp: list, res: list, k: int, vertical:set, diagonal_pus: set, diagonal_minus: set):
        if k == n:
            ans = ["".join(row) for row in tmp]
            res.append(ans)
            return

        for j in range(n):
            if j not in vertical and (k + j) not in diagonal_pus and (k - j) not in diagonal_minus:
                vertical.add(j)
                diagonal_pus.add(k + j)
                diagonal_minus.add(k - j)
                tmp[k][j] = 'Q'
                self.dfs(n, tmp, res, k + 1, vertical, diagonal_pus, diagonal_minus)
                tmp[k][j] = '.'
                vertical.remove(j)
                diagonal_pus.remove(k + j)
                diagonal_minus.remove(k - j)
        

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        self.helper(n, 0, 0, 0, 0, [], res)
        return res

    def helper(self, n:int, row: int, col: int, left: int, right: int, ans: list, res: list):
        if row == n:
            res.append([''.join(x) for x in ans])
            return

        taken = col | left | right
        mask = ~taken & ((1 << n) - 1)

        while mask > 0:
            pos = mask & (-mask)

            tmp = ['Q' if 2 ** j == pos else '.' for j in range(n)]
            ans.append(tmp)
            self.helper(n, row + 1, col | pos, (left | pos) << 1, (right | pos) >> 1, ans, res)
            ans.pop()

            mask &= mask - 1