class Solution {
public:
    bool isValid(string s) {
        stack<char> sstack;
        unordered_map<char, char> pairs;
        pairs[')'] = '(';
        pairs[']'] = '[';
        pairs['}'] = '{';

        for (auto c : s){
            if (pairs.count(c) == 0)
            {
                sstack.push(c);
            }
            else
            {
                if (sstack.empty())
                {
                    return false;
                }

                char candidate = sstack.top();
                sstack.pop();
                if (candidate != pairs[c])
                {
                    return false;
                }
            }
        }

        return sstack.empty();
    }
};
