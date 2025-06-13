//  Tag: Hash Table
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-244
//  Note: -

//  This is a **follow up** of [Shortest Word Distance](https://www.lintcode.com/problem/924/).
//  The only difference is now you are given the list of words and your method will be called `repeatedly` many times with different parameters.
//  How would you optimize it?
//  
//  Design a class which receives a list of words in the constructor, and implements a method that takes two words `word1` and `word2` and return the shortest distance between these two words in the list.
//  
//  **Example 1**
//  
//  Input:
//  
//  ```plaintext
//  ["practice", "makes", "perfect", "coding", "makes"]
//  ["practice", "coding"]
//  ["coding", "makes"]
//  ```
//  
//  Output:
//  
//  ```plaintext
//  3
//  1
//  ```
//  
//  **Example 2**
//  
//  input:
//  
//  ```plaintext
//  ["quia", "blanditiis", "dolores", "sed", "tenetur", "eos", "unde", "tenetur", "blanditiis", "ducimus"]
//  ["tenetur", "blanditiis"]
//  ["blanditiis", "dolores"]
//  ["unde", "eos"]
//  ```
//  
//  Output:
//  
//  ```plaintext
//  1
//  1
//  1
//  ```
//  
//  You may assume that $ word1 \neq word2$, and `word1` and `word2` are **both in the list**.

class WordDistance {
public:
    unordered_map<string, vector<int>> indexes;
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            indexes[wordsDict[i]].push_back(i);
        }
    }

    /**
     * @param word1: word1
     * @param word2: word2
     * @return: the shortest distance between two words
     */
    int shortest(string &word1, string &word2) {
        // write your code here
        vector<int> index1 = indexes[word1];
        vector<int> index2 = indexes[word2];
        int n = index1.size();
        int m = index2.size();
        int res = INT_MAX;
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            res = min(res, abs(index1[i] - index2[j]));
            if (index1[i] < index2[j]) {
                i += 1;
            } else {
                j += 1;
            }
        }
        return res;
    }
};