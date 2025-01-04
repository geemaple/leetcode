#  Tag: Array, Hash Table, Greedy, Sorting
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
#  Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
#   
#  Example 1:
#  
#  Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
#  Output: true
#  Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
#  
#  Example 2:
#  
#  Input: hand = [1,2,3,4,5], groupSize = 4
#  Output: false
#  Explanation: Alice's hand can not be rearranged into groups of 4.
#  
#  
#   
#  Constraints:
#  
#  1 <= hand.length <= 104
#  0 <= hand[i] <= 109
#  1 <= groupSize <= hand.length
#  
#   
#  Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
#  

from collections import Counter

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        n = len(hand)
        counter = Counter(hand)
        hand.sort()

        for cur in hand:
            if counter[cur] > 0:
                for i in range(groupSize):
                    counter[cur + i] -= 1
                    if counter[cur + i] < 0:
                        return False

        return True