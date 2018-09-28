class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        
        people.sort(key=lambda (h, k): (-h, k))

        res = []
        for i in range(len(people)):
            if people[i][1] < len(res):
                res.insert(people[i][1], people[i])
            else:
                res.append(people[i])

        return res