//f(x) = f(x >> 1) + x % 2
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> table;

        for(auto i = 0; i <= num; ++i)
        {
            table.push_back(i % 2);

            int pre = i >> 1;
            if (pre > 0)
            {
                table[i] += table[pre];
            }
        }

        return table;
    }
};
