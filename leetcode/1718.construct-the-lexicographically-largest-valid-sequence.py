#  Tag: Array, Backtracking
#  Time: O(N!)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/3Z75z9sojwg

#  Given an integer n, find a sequence that satisfies all of the following:
#  
#  The integer 1 occurs once in the sequence.
#  Each integer between 2 and n occurs twice in the sequence.
#  For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
#  
#  The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
#  Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution. 
#  A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.
#   
#  Example 1:
#  
#  Input: n = 3
#  Output: [3,1,2,3,2]
#  Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
#  
#  Example 2:
#  
#  Input: n = 5
#  Output: [5,3,1,4,3,5,2,4,2]
#  
#   
#  Constraints:
#  
#  1 <= n <= 20
#  
#  

class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        res = [0 for i in range(2 * n - 1)]
        used = [False for i in range(n + 1)]
        self.helper(0, res, n, used)
        return res

    def helper(self, i: int, res: list, n: int, used: list) -> bool:
        if i == len(res):
            return True

        if res[i] != 0:
            return self.helper(i + 1, res, n, used)

        for num in range(n, 0, -1):
            if used[num]:
                continue

            j = i + num if num > 1 else i
            if j < len(res) and res[j] == 0:
                used[num] = True
                res[i] = res[j] = num
                if self.helper(i + 1, res, n, used):
                    return True
                res[i] = res[j] = 0
                used[num] = False

        return False