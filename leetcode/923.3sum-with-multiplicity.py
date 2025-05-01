#  Tag: Array, Hash Table, Two Pointers, Sorting, Counting
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
#  As the answer can be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
#  Output: 20
#  Explanation: 
#  Enumerating by the values (arr[i], arr[j], arr[k]):
#  (1, 2, 5) occurs 8 times;
#  (1, 3, 4) occurs 8 times;
#  (2, 2, 4) occurs 2 times;
#  (2, 3, 3) occurs 2 times.
#  
#  Example 2:
#  
#  Input: arr = [1,1,2,2,2,2], target = 5
#  Output: 12
#  Explanation: 
#  arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
#  We choose one 1 from [1,1] in 2 ways,
#  and two 2s from [2,2,2,2] in 6 ways.
#  
#  Example 3:
#  
#  Input: arr = [2,1,3], target = 6
#  Output: 1
#  Explanation: (1, 2, 3) occured one time in the array so we return 1.
#  
#   
#  Constraints:
#  
#  3 <= arr.length <= 3000
#  0 <= arr[i] <= 100
#  0 <= target <= 300
#  
#  

from collections import Counter
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        n = len(arr)
        counter = Counter(arr)
        mod = 10 ** 9 + 7
        res = 0
        for first in counter:
            for second in counter:
                last = target - first - second
                if last not in counter:
                    continue

                if first == second == last:
                    res = (res + counter[first] * (counter[first] - 1) * (counter[first] - 2) // 6) % mod
                elif first == second and second != last:
                    res = (res + counter[first] * (counter[first] - 1) // 2 * counter[last]) % mod
                elif first < second and second < last:
                    res = (res + counter[first] * counter[second] * counter[last]) % mod

        return res
    
from collections import Counter
from math import comb
class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        n = len(arr)
        arr.sort()
        counter = Counter(arr)
        mod = 10 ** 9 + 7
        res = 0
        for k in range(n):
            if k > 0 and arr[k] == arr[k - 1]:
                continue

            l = k + 1
            r = n - 1
            while l <= r:
                tmp = arr[k] + arr[l] + arr[r]
                if tmp == target:
                    if arr[k] == arr[r]:
                        res += comb(counter[arr[k]], 3)
                    elif arr[k] == arr[l]:
                        res += comb(counter[arr[k]], 2) * counter[arr[r]]
                    elif arr[l] == arr[r]:
                        res += comb(counter[arr[l]], 2) * counter[arr[k]]
                    else:
                        res += counter[arr[k]] * counter[arr[l]] * counter[arr[r]]
                    res = res % mod
                    while l < r and arr[l] == arr[l + 1]:
                        l += 1

                    while l <= r and arr[r] == arr[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif tmp > target:
                    r -= 1
                else:
                    l += 1
        return res