// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        
        int candidate = 0;
        for(auto i = 1; i < n; ++i)
        {
            candidate = knows(candidate, i) ? i: candidate;
        }

        for (auto i = 0; i < n; ++i)
        {
            if (candidate == i)
            {
                continue;
            }

            if(knows(candidate, i))
            {
                return -1;
            }

            if (!knows(i, candidate))
            {
                return -1;
            }
        }

        return candidate;
    }
};
