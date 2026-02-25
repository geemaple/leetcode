#  Tag: Backtracking, Bit Manipulation
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -

#  A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
#  
#  For example, the below binary watch reads "4:51".
#  
#  
#  Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
#  The hour must not contain a leading zero.
#  
#  For example, "01:00" is not valid. It should be "1:00".
#  
#  The minute must consist of two digits and may contain a leading zero.
#  
#  For example, "10:2" is not valid. It should be "10:02".
#  
#   
#  Example 1:
#  Input: turnedOn = 1
#  Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
#  Example 2:
#  Input: turnedOn = 9
#  Output: []
#  
#   
#  Constraints:
#  
#  0 <= turnedOn <= 10
#  
#  

class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        res = []
        for h in range(12):
            for m in range(60):
                if (h.bit_count() + m.bit_count()) == turnedOn:
                    res.append(f"{h}:{m:02d}")
        return res

class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        digits = [8, 4, 2, 1, 32, 16, 8, 4, 2, 1]
        res = []

        def dfs(i, ons):
            if len(ons) == turnedOn:
                h = 0
                m = 0
                for num in ons:
                    if num < 4:
                        h += digits[num]
                    else:
                        m += digits[num]

                if h < 12 and m < 60:
                    res.append(f"{h}:{m:02d}")
                return

            
            for j in range(i, len(digits)):
                dfs(j + 1, ons + [j])

        dfs(0, [])
        return res

class Solution:
    def readBinaryWatch(self, turnedOn: int):
        digits = [8,4,2,1,32,16,8,4,2,1]
        res = []

        def dfs(i, ons):
            if len(ons) > turnedOn or len(ons) + (10 - i) < turnedOn:
                return

            if i == 10:
                if len(ons) == turnedOn:
                    h = 0
                    m = 0
                    for num in ons:
                        if num < 4:
                            h += digits[num]
                        else:
                            m += digits[num]

                    if h < 12 and m < 60:
                        res.append(f"{h}:{m:02d}")
                return

            # 不选
            dfs(i + 1, ons)

            # 选
            dfs(i + 1, ons + [i])

        dfs(0, [])
        return res

                
