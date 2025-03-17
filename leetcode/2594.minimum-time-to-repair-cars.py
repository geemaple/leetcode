#  Tag: Array, Binary Search
#  Time: O(AlogN)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/0iwaFdV71Dk

#  You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
#  You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
#  Return the minimum time taken to repair all the cars.
#  Note: All the mechanics can repair the cars simultaneously.
#   
#  Example 1:
#  
#  Input: ranks = [4,2,3,1], cars = 10
#  Output: 16
#  Explanation: 
#  - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
#  - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
#  - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
#  - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
#  It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
#  
#  Example 2:
#  
#  Input: ranks = [5,1,8], cars = 6
#  Output: 16
#  Explanation: 
#  - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
#  - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
#  - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
#  It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
#  
#   
#  Constraints:
#  
#  1 <= ranks.length <= 105
#  1 <= ranks[i] <= 100
#  1 <= cars <= 106
#  
#  

import math
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        l = 1
        r = min(ranks) * cars * cars

        while l < r:
            m = l + (r - l) // 2
            if self.fit(ranks, m, cars):
                r = m
            else:
                l = m + 1
        return l

    def fit(self, ranks: list, k: int, cars: int) -> bool:
        res = 0
        n = len(ranks)
        i = 0
        while i < n and res < cars:
            if ranks[i] <= k:
                res += math.floor(math.sqrt(k // ranks[i]))
            i += 1

        return res >= cars
    
from collections import Counter
import heapq
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        counter = Counter(ranks)
        heap = []
        for rank, count in counter.items():
            time = rank
            heapq.heappush(heap, (time, rank, 1, count))

        time = 0
        while cars > 0:
            time, rank, fixed, count = heapq.heappop(heap)
            cars -= count
            fixed += 1
            heapq.heappush(heap, (rank * fixed * fixed, rank, fixed, count))

        return time