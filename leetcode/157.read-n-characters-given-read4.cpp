// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buffer[4];
        int offset = 0;
        int total = 0;

        for(auto i = 0; i < n; ++i)
        {
            if (offset == total)
            {
                total = read4(buffer);
                offset = 0;
            }

            if (offset < total){
                buf[i] = buffer[offset++];
            }
            else
            {
                return i;
            }
        }

        return n;
    }
};
