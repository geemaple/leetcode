class Solution {
public:
    vector<int> findAnagrams(string s, string p) {


        int size = p.size();
        int left = size;
        
        vector<int> res;
        unordered_map<char, int> counting;

        for (auto c : p)
        {
            counting[c] += 1;
        }    

        int back = 0;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (counting.count(s[i]) > 0){
                counting[s[i]]--;
                if (counting[s[i]] >= 0){
                    left--;
                }
            }

            if (i - back + 1 == size)
            {
                if (left == 0)
                {
                    res.push_back(back);
                }

                if (counting.count(s[back]) > 0){
                    counting[s[back]]++;
                    if (counting[s[back]] > 0){
                        left++;
                    }
                }

                back ++;
            }
        }

        return res;
    }
};
