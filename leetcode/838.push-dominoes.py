#  Tag: Two Pointers, String, Dynamic Programming
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/SbDNsalMz7A

#  There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
#  After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
#  When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
#  For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
#  You are given a string dominoes representing the initial state where:
#  
#  dominoes[i] = 'L', if the ith domino has been pushed to the left,
#  dominoes[i] = 'R', if the ith domino has been pushed to the right, and
#  dominoes[i] = '.', if the ith domino has not been pushed.
#  
#  Return a string representing the final state.
#   
#  Example 1:
#  
#  Input: dominoes = "RR.L"
#  Output: "RR.L"
#  Explanation: The first domino expends no additional force on the second domino.
#  
#  Example 2:
#  
#  
#  Input: dominoes = ".L.R...LR..L.."
#  Output: "LL.RR.LLRRLL.."
#  
#   
#  Constraints:
#  
#  n == dominoes.length
#  1 <= n <= 105
#  dominoes[i] is either 'L', 'R', or '.'.
#  
#  

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        left = [float('inf') for i in range(n)]

        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'R':
                continue
            if dominoes[i] == 'L':
                left[i] = 0
            elif i + 1 < n and left[i + 1] >= 0:
                left[i] = left[i + 1] + 1

        res = list(dominoes)
        right = float('inf')
        for i in range(n):
            if dominoes[i] == 'L':
                right = float('inf')
            elif dominoes[i] == 'R':
                right = 0
            elif i > 0 and right >= 0:
                right += 1

            if right != left[i]:
                res[i] = 'R' if right < left[i] else 'L'

        return ''.join(res)

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        dominoes = 'L' + dominoes + 'R'
        res = ""
        i = 0
        for j in range(1, len(dominoes)):
            if dominoes[j] == '.':
                continue
            middle = j - i - 1
            if i > 0:
                res += dominoes[i]
                
            if dominoes[i] == dominoes[j]:
                res += dominoes[i] * middle
            elif dominoes[i] == 'L' and dominoes[j] == 'R':
                res += '.' * middle
            else:
                res += 'R' * (middle // 2) + '.' * (middle % 2) + 'L' * (middle // 2)
            i = j
        return res