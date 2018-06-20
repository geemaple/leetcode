class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        unordered_set<char> set(J.begin(), J.end());
        int count = 0;
        for (auto str: S){
            if (set.count(str) > 0){
                count += 1;
            }
        }
        
        return count;
    }
};