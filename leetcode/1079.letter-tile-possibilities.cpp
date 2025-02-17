//  Tag: Hash Table, String, Backtracking, Counting
//  Time: O(N!)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/Q2z9GbjkWmo

//  You have n  tiles, where each tile has one letter tiles[i] printed on it.
//  Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
//   
//  Example 1:
//  
//  Input: tiles = "AAB"
//  Output: 8
//  Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
//  
//  Example 2:
//  
//  Input: tiles = "AAABBC"
//  Output: 188
//  
//  Example 3:
//  
//  Input: tiles = "V"
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= tiles.length <= 7
//  tiles consists of uppercase English letters.
//  
//  

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        vector<bool> used(n, false);
        vector<string> res;
        helper(tiles, used, res, "");

        return res.size();
    }

    void helper(string tiles, vector<bool> &used, vector<string> &res, string tmp) {
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) {
                continue;
            }

            if (i == 0 || tiles[i] != tiles[i - 1] || used[i - 1]) {
                used[i] = true;
                string sub = tmp + tiles[i];
                res.push_back(sub);
                helper(tiles, used, res, sub);
                used[i] = false;
            }
        }
    }
};

class Solution {
public:
    int res = 0;

    int numTilePossibilities(string tiles) {
        unordered_map<char,int>map;
        for(char ch : tiles) {
            map[ch]++;
        }   
        backtrack(map); 
        return res;
    }

    void backtrack(unordered_map<char, int>& map) {
        for(auto &[ch,count] : map) {
            if(count > 0) {
                res++;
                map[ch]--;
                backtrack(map);
                map[ch]++;
            }
        }
    }
};