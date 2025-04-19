#  Tag: Array, Two Pointers, Binary Search, Sorting
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
#  A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
#  
#  age[y] <= 0.5 * age[x] + 7
#  age[y] > age[x]
#  age[y] > 100 && age[x] < 100
#  
#  Otherwise, x will send a friend request to y.
#  Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
#  Return the total number of friend requests made.
#   
#  Example 1:
#  
#  Input: ages = [16,16]
#  Output: 2
#  Explanation: 2 people friend request each other.
#  
#  Example 2:
#  
#  Input: ages = [16,17,18]
#  Output: 2
#  Explanation: Friend requests are made 17 -> 16, 18 -> 17.
#  
#  Example 3:
#  
#  Input: ages = [20,30,100,110,120]
#  Output: 3
#  Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
#  
#   
#  Constraints:
#  
#  n == ages.length
#  1 <= n <= 2 * 104
#  1 <= ages[i] <= 120
#  
#  

from collections import Counter
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        n = len(ages)
        counter = Counter(ages)
        res = 0
        count = 0
        i = 15
        for j in range(15, 121):
            while i < j // 2 + 8:
                count -= counter[i]
                i += 1

            count += counter[j]
            res += count * counter[j] - counter[j]

        return res

from collections import Counter
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        counter = Counter(ages)
        res = 0
        for i in range(15, 121):
            for j in range(i // 2 + 8, i + 1):
                res += counter[i] * (counter[j] - (i == j))

        return res
    
import bisect
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        n = len(ages)
        ages.sort()
        res = 0
        count = 1
        for j in range(n - 1, -1, -1):
            if ages[j] < 15:
                break

            if j >= 1 and ages[j] == ages[j - 1]:
                count += 1
                continue

            k = ages[j] // 2 + 7        
            i = bisect.bisect_right(ages, k)
            res += (j - i) * count + count * (count - 1)
            count = 1
        return res