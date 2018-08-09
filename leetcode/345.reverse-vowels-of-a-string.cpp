class Solution {
public:
    string reverseVowels(string s) {
        
        int left = 0;
        int right = (int)(s.size() - 1);
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        
        while (left < right) {
            
            while (left < right and vowels.count(tolower(s[left])) == 0) {
                left++;
            }
            
            while (left < right and vowels.count(tolower(s[right])) == 0) {
                right--;
            }
            
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            
            left++;
            right--;
        }
        
        return s;
    }
};
