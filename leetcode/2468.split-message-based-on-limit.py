#  Tag: String, Binary Search
#  Time: O(logN + K)
#  Space: O(1)
#  Ref: -
#  Note: Answer | Bruteforce

#  You are given a string, message, and a positive integer, limit.
#  You must split message into one or more parts based on limit. Each resulting part should have the suffix "<a/b>", where "b" is to be replaced with the total number of parts and "a" is to be replaced with the index of the part, starting from 1 and going up to b. Additionally, the length of each resulting part (including its suffix) should be equal to limit, except for the last part whose length can be at most limit.
#  The resulting parts should be formed such that when their suffixes are removed and they are all concatenated in order, they should be equal to message. Also, the result should contain as few parts as possible.
#  Return the parts message would be split into as an array of strings. If it is impossible to split message as required, return an empty array.
#   
#  Example 1:
#  
#  Input: message = "this is really a very awesome message", limit = 9
#  Output: ["thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]
#  Explanation:
#  The first 9 parts take 3 characters each from the beginning of message.
#  The next 5 parts take 2 characters each to finish splitting message. 
#  In this example, each part, including the last, has length 9. 
#  It can be shown it is not possible to split message into less than 14 parts.
#  
#  Example 2:
#  
#  Input: message = "short message", limit = 15
#  Output: ["short mess<1/2>","age<2/2>"]
#  Explanation:
#  Under the given constraints, the string can be split into two parts: 
#  - The first part comprises of the first 10 characters, and has a length 15.
#  - The next part comprises of the last 3 characters, and has a length 8.
#  
#   
#  Constraints:
#  
#  1 <= message.length <= 104
#  message consists only of lowercase English letters and ' '.
#  1 <= limit <= 104
#  
#  

class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        
        digit_min = 1
        digit_max = limit - 4

        digit = None
        for i in range(digit_min, digit_max):
            if self.feasible(message, limit, 10 ** i - 1):
                digit = i
                break

        if digit is None:
            return []
    
        start = 10 ** (digit - 1)
        end = 10 ** digit - 1

        while start < end:
            mid = start + (end - start) // 2
            if self.feasible(message, limit, mid):
                end = mid
            else:
                start = mid + 1

        return self.printout(message, limit, start)

    def feasible(self, message: str, limit: int, part: int) -> bool:
        suffix = 4 + len(str(part))
        place = limit - suffix
        num = 9
        total = 0
        test = 0
        while part > num + test and place > 0:
            total += num * place
            test += num    
            num *= 10
            place -= 1

        total += (part - test) * place
        return total >= len(message)
        
    def printout(self, message: str, limit: int, part: int) -> List[str]:
        res = []
        j = 0
        for i in range(1, part + 1):
            suffix = f'<{i}/{part}>'
            offset = limit - len(suffix)
            item = message[j: j + offset] + suffix
            res.append(item)
            j += offset

        return res
    
class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        
        cur = 1
        k = 1
        while len(message) + (3 + len(str(k))) * k +  cur > k * limit and 1 + 3 + len(str(k)) < limit:
            k += 1
            cur += len(str(k))

        if 1 + 3 + len(str(k)) >= limit:
            return []

        return self.printout(message, limit, k)

        
    def printout(self, message: str, limit: int, part: int) -> List[str]:
        res = []
        j = 0
        for i in range(1, part + 1):
            suffix = f'<{i}/{part}>'
            offset = limit - len(suffix)
            item = message[j: j + offset] + suffix
            res.append(item)
            j += offset

        return res