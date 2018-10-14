// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            int result = guess(mid);
            if (result < 0)
            {
                end = mid;
            }
            else if (result > 0)
            {
                start = mid;
            }
            else
            {
                return mid;
            }
        }
        
        return guess(start) == 0 ? start : end;
    }
};