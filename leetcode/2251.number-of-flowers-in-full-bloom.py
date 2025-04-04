#  Tag: Array, Hash Table, Binary Search, Sorting, Prefix Sum, Ordered Set
#  Time: O(NlogN + MlogM)
#  Space: O(N + M)
#  Ref: -
#  Note: -

#  You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.
#  Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
#   
#  Example 1:
#  
#  
#  Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
#  Output: [1,2,2,2]
#  Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
#  For each person, we return the number of flowers in full bloom during their arrival.
#  
#  Example 2:
#  
#  
#  Input: flowers = [[1,10],[3,3]], people = [3,3,2]
#  Output: [2,2,1]
#  Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
#  For each person, we return the number of flowers in full bloom during their arrival.
#  
#   
#  Constraints:
#  
#  1 <= flowers.length <= 5 * 104
#  flowers[i].length == 2
#  1 <= starti <= endi <= 109
#  1 <= people.length <= 5 * 104
#  1 <= people[i] <= 109
#  
#  

from collections import defaultdict
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        n = len(flowers)
        line = defaultdict(int)
        for s, e in flowers:
            line[s] += 1
            line[e + 1] -= 1

        index_people = [(people[i], i) for i in range(len(people))]
        index_people.sort()
        res = [0 for i in range(len(people))]

        prefix = 0
        i = 0
        times = sorted(line.keys())
        print([(t, line[t]) for t in times])
        for t, idx in index_people:
            while i < len(line) and t >= times[i]:
                prefix += line[times[i]]
                i += 1

            res[idx] = prefix

        return res