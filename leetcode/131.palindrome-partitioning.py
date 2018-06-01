class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """

        if s is None:
            return []    

        results = []
        partitions = []
        self.helper(s, partitions, results, 0)
        return results

    def helper(self, s, partitions, results, start):
        
        if start == len(s):
            results.append(list(partitions))

        for i in range(start, len(s)):
            sub = s[start: i + 1]
            if not self.is_palindrome(sub):
                continue

            partitions.append(sub)
            self.helper(s, partitions, results, i + 1)
            partitions.pop()


    def is_palindrome(self, part):
        length = len(part)
        if length <= 1:
            return True
        
        for i in range(length):
            if part[i] != part[length - 1 - i]:
                return False

        return True

    # since is_palindrome func is called most,
    # we can optimize this with a prebuit matrix
    def build_matrix(self, s):

        def expand(matrix, begin, end):
            # A palindrome added the SAME char to both sides is aslo a valid palindrome
            while (begin - 1 >= 0 and end + 1 <= size):
                matrix[begin - 1][end + 1] = matrix[begin][end] & int(s[begin - 1] == s[end])
                begin = begin - 1
                end = end + 1
 
        size = len(s)
        # (n + 1) * n
        matrix = [[0 for _ in range(size + 1)] for _ in range(size)]

        for i in range(size):
            # s[i:i] = '' 
            matrix[i][i] = 1
            expand(matrix, i, i)
            if i + 1 <= size:
                # s[i: i + 1] = 'a single char' 
                matrix[i][i + 1] = 1
                expand(matrix, i, i + 1)