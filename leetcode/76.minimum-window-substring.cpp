class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size()){
            return "";
        }
        unordered_map<char, int> count_map;
        int remains = t.size();
        int j = 0;
        int start = 0;
        int end = INT_MAX;

        for (auto c : t){
            count_map[c] ++;
         }

        for (int i = 0; i < s.size(); ++i){

            while (j < s.size() && remains > 0)
            {
                if (count_map.count(s[j]) > 0)
                {
                    count_map[s[j]] -= 1;
                    if (count_map[s[j]] >= 0)
                    {
                        remains --;
                    }
                }

                j++;
            }

            if (remains == 0 && end - start > j - i)
            {
                start = i;
                end = j;
            }

            if (count_map.count(s[i]) > 0)
            {
                count_map[s[i]] += 1;
                if (count_map[s[i]] > 0)
                {
                    remains ++;
                }
            }
        }

        return (end == INT_MAX) ? "" : s.substr(start, end - start);

    }
};
  