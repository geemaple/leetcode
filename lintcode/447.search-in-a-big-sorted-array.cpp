class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int start = 0;
        int end = 1; // 2^0, 2^1, 2^2, 2^3, 2^4...
        
        int res = reader->get(end);
        while(res != INT_MAX && res < target)
        {
            start = end;
            end = end << 1;
            
            res = reader->get(end);
        }
        
        
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            int res = reader->get(mid);
            
            if (res >= target)
            {
                end = mid;
            }
            else if (res < target)
            {
                start = mid;
            }
        }
        
        if (reader->get(start) == target)
        {
            return start;
        }
        
        if (reader->get(end) == target)
        {
            return end;
        }
        
        return -1;
    }
};