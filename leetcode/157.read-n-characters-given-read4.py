# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        buffer = [0] * 4
        offset = 0
        total = 0

        for i in range(n):
            if offset == total:
                total = read4(buffer)
                offset = 0

            if offset < total:
                buf[i] = buffer[offset]
                offset += 1
            else:
                return i

        return n