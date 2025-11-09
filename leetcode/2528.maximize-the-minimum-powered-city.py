#  Tag: Array, Binary Search, Greedy, Queue, Sliding Window, Prefix Sum
#  Time: O(NLogA)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.
#  Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.
#  
#  Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
#  
#  The power of a city is the total number of power stations it is being provided power from.
#  The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.
#  Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.
#  Note that you can build the k power stations in multiple cities.
#   
#  Example 1:
#  
#  Input: stations = [1,2,4,5,0], r = 1, k = 2
#  Output: 5
#  Explanation: 
#  One of the optimal ways is to install both the power stations at city 1. 
#  So stations will become [1,4,4,5,0].
#  - City 0 is provided by 1 + 4 = 5 power stations.
#  - City 1 is provided by 1 + 4 + 4 = 9 power stations.
#  - City 2 is provided by 4 + 4 + 5 = 13 power stations.
#  - City 3 is provided by 5 + 4 = 9 power stations.
#  - City 4 is provided by 5 + 0 = 5 power stations.
#  So the minimum power of a city is 5.
#  Since it is not possible to obtain a larger power, we return 5.
#  
#  Example 2:
#  
#  Input: stations = [4,4,4,4], r = 0, k = 3
#  Output: 4
#  Explanation: 
#  It can be proved that we cannot make the minimum power of a city greater than 4.
#  
#   
#  Constraints:
#  
#  n == stations.length
#  1 <= n <= 105
#  0 <= stations[i] <= 105
#  0 <= r <= n - 1
#  0 <= k <= 109
#  
#  

class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        left = 0
        right = sum(stations) + k
        while left < right:
            mid = left + (right - left + 1) // 2
            if self.fit(stations, mid, r, k):
                left = mid
            else:
                right = mid - 1

        return left

    def fit(self, stations: list, mid: int, r: int, k: int) -> bool:
        n = len(stations)
        power = sum(stations[:r])
        additions = [0] * n
        for i in range(n):
            if i + r < n:
                power += stations[i + r]

            if power < mid:
                needed = mid - power
                if needed > k:
                    return False

                additions[min(n - 1, i + r)] += needed
                power += needed
                k -= needed

            if i - r >= 0:
                power -= stations[i - r] + additions[i - r]
                
        return True