#  Tag: Enumerate, Array, Simulation
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Find the *N*th number in Fibonacci sequence.
#  (N starts at 1)
#  
#  A Fibonacci sequence is defined as follow:
#  
#  - The first two numbers are 0 and 1.
#  - The *i* th number is the sum of *i*-1 th number and *i*-2 th number.
#  
#  The first ten numbers in Fibonacci sequence is:
#  
#  `0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...`
#  
#  ```
#  Example 1:
#  	Input:  1
#  	Output: 0
#  	
#  	Explanation: 
#  	return the first number in  Fibonacci sequence .
#  
#  Example 2:
#  	Input:  2
#  	Output: 1
#  	
#  	Explanation: 
#  	return the second number in  Fibonacci sequence .
#  
#  ```
#  
#  The *N*th fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.

class Solution:
    """
    @param n: an integer
    @return: an integer f(n)
    """
    def fibonacci(self, n: int) -> int:
        # write your code here
        if n <= 2:
            return n - 1

        dp = [0 for i in range(n)]
        dp[1] = 1
        for i in range(2, n):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n - 1]