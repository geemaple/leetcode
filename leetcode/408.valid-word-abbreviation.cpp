class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int left = 0;
        int right = 0;
        
        while(left < word.size() && right < abbr.size())
        {
            if (abbr[right] == '0')
            {
                return false;
            }
            else if (abbr[right] > '0' && abbr[right] <= '9')
            {
                int step = abbr[right] - '0';
                while(right + 1 < abbr.size() && abbr[right + 1] >= '0' && abbr[right + 1] <= '9')
                {
                    step = (step * 10) + (abbr[right + 1] - '0');
                    right++;
                }
                left += step;
                right += 1;
                continue;
            }
            else if(word[left] != abbr[right])
            {
                return false;
            }
            
            left += 1;
            right += 1;
        }
        
        return (left == word.size()  && right == abbr.size());
    }
};