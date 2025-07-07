//  Tag: Math, Bit Manipulation, Recursion, Simulation
//  Time: O(logK)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/vZQSipSk2Fk

//  Alice and Bob are playing a game. Initially, Alice has a string word = "a".
//  You are given a positive integer k.
//  Now Bob will ask Alice to perform the following operation forever:
//  
//  Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
//  
//  For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
//  Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.
//  Note that the character 'z' can be changed to 'a' in the operation.
//   
//  Example 1:
//  
//  Input: k = 5
//  Output: "b"
//  Explanation:
//  Initially, word = "a". We need to do the operation three times:
//  
//  Generated string is "b", word becomes "ab".
//  Generated string is "bc", word becomes "abbc".
//  Generated string is "bccd", word becomes "abbcbccd".
//  
//  
//  Example 2:
//  
//  Input: k = 10
//  Output: "c"
//  
//   
//  Constraints:
//  
//  1 <= k <= 500
//  
//  

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            string tmp = "";
            for (auto &ch: word) {
                tmp += (ch - 'a' + 1) % 26 + 'a';
            }
            word += tmp;
        }

        return word[k - 1];
    }
};

class Solution {
public:
    char kthCharacter(int k) {
        int l = ceil(log2(k));
        return getChar(l, k - 1);
    }

    char getChar(int l, int k) {
        if (l == 0) {
            return 'a';
        }
        int half = 1 << (l - 1);
        if (k < half) {
            return getChar(l - 1, k);
        } else {
            return getChar(l - 1, k - half) + 1;
        }
    }
};

class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};