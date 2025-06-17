#  Tag: Math, Greedy
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/9kBNJ-ZfHAQ

#  You are given an integer num. You will apply the following steps to num two separate times:
#  
#  Pick a digit x (0 <= x <= 9).
#  Pick another digit y (0 <= y <= 9). Note y can be equal to x.
#  Replace all the occurrences of x in the decimal representation of num by y.
#  
#  Let a and b be the two results from applying the operation to num independently.
#  Return the max difference between a and b.
#  Note that neither a nor b may have any leading zeros, and must not be 0.
#   
#  Example 1:
#  
#  Input: num = 555
#  Output: 888
#  Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
#  The second time pick x = 5 and y = 1 and store the new integer in b.
#  We have now a = 999 and b = 111 and max difference = 888
#  
#  Example 2:
#  
#  Input: num = 9
#  Output: 8
#  Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
#  The second time pick x = 9 and y = 1 and store the new integer in b.
#  We have now a = 9 and b = 1 and max difference = 8
#  
#   
#  Constraints:
#  
#  1 <= num <= 108
#  
#  

class Solution:
    def maxDiff(self, num: int) -> int:
        max_v = str(num)
        min_v = str(num)

        for d in max_v:
            if d != '9':
                max_v = max_v.replace(d, '9')
                break

        for i, d in enumerate(min_v):
            if i == 0:
                if d != '1':
                    min_v = min_v.replace(d, '1')
                    break
            else:
                if d != '0' and d != min_v[0]:
                    min_v = min_v.replace(d, '0')
                    break

        return int(max_v) - int(min_v)

class Solution:
    def maxDiff(self, num: int) -> int:
        max_v = num
        min_v = num

        first = 0
        n = num
        while n > 0:
            first = n % 10
            n //= 10

        for i in range(10):
            high = 0
            low = 0
            n = num
            mul = 1
            while n > 0:
                replace = ((n % 10) == i)
                high += (9 if replace else n % 10) * mul
                low += ((1 if n % 10 == first else 0) if replace else n % 10) * mul
                mul *= 10
                n //= 10

            max_v = max(max_v, high)
            if low > 0:
                min_v = min(min_v, low)
                
        return max_v - min_v