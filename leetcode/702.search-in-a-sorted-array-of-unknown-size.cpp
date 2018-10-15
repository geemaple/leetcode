// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start = 0;
        int end = 1;
        
        int res = reader.get(end);
        while (res != INT_MAX && res < target)
        {
            start = end;
            end = end * 2;
            res = reader.get(end);
        }
        
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            res = reader.get(mid);
            
            if (res < target)
            {
                start = mid;
            }
            else if (res > target)
            {
                end = mid;
            }
            else
            {
                return mid;
            }
        }
        
        if (reader.get(start) == target)
        {
            return start;
        }
        
        if (reader.get(end) == target)
        {
            return end;
        }
        
        return -1;
    }
};