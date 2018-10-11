// Rabin-Karp
class Solution {
private:
    int const k_characters = 256;
    int const k_bucket = 131;
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0)
        {
            return 0;
        }
        
        if (n > m)
        {
            return -1;
        }
        
        int target = 0;
        int tmp = 0;
        int high = 1;
        
        for (auto i = 0; i < n - 1; ++i)
        {
            high = (high * k_characters) % k_bucket;
        }
        
        for (auto i = 0; i < n; ++i)
        {
            target = (target * k_characters + needle[i]) % k_bucket;
            tmp = (tmp * k_characters + haystack[i]) % k_bucket;
        }
        
        for (auto i = 0; i < m - n + 1; ++i)
        {
            if (tmp == target)
            {
                bool match = true;
                for (auto j = 0; j < n; ++j)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        match = false;
                        break;
                    }
                }
                
                if (match)
                {
                    return i;
                }
            }
            
            if (i < m - n)
            {
                tmp = ((tmp - haystack[i] * high) * k_characters + haystack[i + n]) % k_bucket;
                if (tmp < 0)
                {
                    tmp += k_bucket;
                }
            }
        }
        
        return -1;
    }
};

class Solution2 {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.size();
        int n = needle.size();

        if (n == 0)
        {
            return 0;
        }

        if (n > m)
        {
            return -1;
        }

        for (auto i = 0; i < m - n + 1; ++i)
        {
            bool match = true;
            for (auto j = 0; j < n; ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return i;
            }
        }

        return -1;
    }
};
