# O(N) N = len(positions)
class Solution(object):
    def numIslands2(self, m, n, positions):
        """
        :type m: int
        :type n: int
        :type positions: List[List[int]]
        :rtype: List[int]
        """

        if positions is None or len(positions) == 0:
            return []

        count = 0
        uf = UnionFind(m * n)
        islands = set()
        results = []

        # top, left, bottom, right
        x_move = [-1, 0, 1, 0]
        y_move = [0, -1, 0, 1]


        for point in positions:
            x = point[0]
            y = point[1]

            if (x, y) not in islands:
                count += 1
                islands.add((x, y))

                # check top, left, bottom, right
                for i in range(4):
                    neighbor_x = x_move[i] + x
                    neighbor_y = y_move[i] + y

                    # check boundry
                    if 0 <= neighbor_x < m and 0 <= neighbor_y < n and (neighbor_x, neighbor_y) in islands:
                        point = self.flatten_pos(x, y, n)
                        neighbor = self.flatten_pos(neighbor_x, neighbor_y, n)
                        if uf.union(point, neighbor):
                            count -= 1

            results.append(count)

        return results

    def flatten_pos(self, x, y, column):
        return x * column + y


class UnionFind(object):
    def __init__(self, count):
        self.table = [i for i in range(count)]

    def find(self, x):
        if self.table[x] == x:
            return x
        
        self.table[x] = self.find(self.table[x])
        return self.table[x]

    def union(self, x, y):
        super_x = self.find(x)
        super_y = self.find(y)

        if super_x != super_y:
            self.table[super_x] = self.table[super_y]
            return True
        
        return False