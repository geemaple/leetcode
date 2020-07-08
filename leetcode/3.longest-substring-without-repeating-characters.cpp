class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0;
        unordered_set<char> visited;

        for(int i = 0; i < s.size(); ++i){
            while(visited.count(s[i]) > 0){
                visited.erase(s[left++]);
            }

            visited.insert(s[i]);
            res = max(res, i - left + 1);
        }

        return res;
    }
};

class Solution2 {
private:
    static const int ASCII_COUNT = 256;
public:
    int lengthOfLongestSubstring(string s) {
        
        int res = 0;
        int left = 0;
        vector<int> visited(ASCII_COUNT, - 1);

        for(int i = 0; i < s.size(); ++i){

            if (visited[s[i]] >= 0){
                left  = max(visited[s[i]] + 1, left);
            }

            visited[s[i]] = i;
            res = max(res, i - left + 1);
        }

        return res;
    }
};



