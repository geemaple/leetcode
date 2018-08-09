class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.size() == 0)
        {
            return 0;
        }

        if (needle.size() > haystack.size())
        {
            return -1;
        }

        for (int i = 0; i < haystack.size(); ++i)
        {

            if (i + needle.size() - 1 >= haystack.size())
            {
                continue;
            }

            bool match = true;
            for (int j = 0; j < needle.size(); ++j)
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
