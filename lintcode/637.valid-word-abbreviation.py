#  Tag: String, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-408
#  Note: -

#  Given a **non-empty** string `word` and an abbreviation `abbr`, return whether the string matches with the given abbreviation.
#  
#  A string such as `"word"` contains only the following valid abbreviations:
#  ```
#  ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
#  ```
#  
#  **Example 1:**
#  ```
#  Input : s = "internationalization", abbr = "i12iz4n"
#  Output : true
#  ```
#  **Example 2:**
#  ```
#  Input : s = "apple", abbr = "a2e"
#  Output : false
#  ```
#  
#  Where 1 means one character is omitted, 2 means two characters are omitted, and so on.
#  Notice that only the above abbreviations are valid abbreviations of the string `word`. Any other string is not a valid abbreviation of `word`.

class Solution:
    """
    @param word: a non-empty string
    @param abbr: an abbreviation
    @return: true if string matches with the given abbr or false
    """
    def valid_word_abbreviation(self, word: str, abbr: str) -> bool:
        # write your code here
        i = 0
        j = 0
        while i < len(word) and j < len(abbr):
            if word[i] == abbr[j]:
                i += 1
                j += 1
            elif abbr[j].isdigit() and abbr[j] != '0':
                start = j
                while j < len(abbr) and abbr[j].isdigit():
                    j += 1
                i += int(abbr[start : j])
            else:
                return False

        return i == len(word) and j == len(abbr)



