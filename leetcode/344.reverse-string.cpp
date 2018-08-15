class Solution {
public:
    string reverseString(string s) {
        
        int start = 0;
        int end = (int)(s.size() - 1);

        while(start < end)
        {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;

            start++;
            end--;
        }
        
        return s;
    }
};
