#  Tag: Array, Hash Table, String
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/mOenT2NR8l0

#  Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
#  For a given query word, the spell checker handles two categories of spelling mistakes:
#  
#  Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
#  
#  	
#  Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
#  Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
#  Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
#  
#  
#  Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
#  	
#  Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
#  Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
#  Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
#  
#  
#  
#  In addition, the spell checker operates under the following precedence rules:
#  
#  When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
#  When the query matches a word up to capitlization, you should return the first such match in the wordlist.
#  When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
#  If the query has no matches in the wordlist, you should return the empty string.
#  
#  Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
#   
#  Example 1:
#  Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
#  Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
#  Example 2:
#  Input: wordlist = ["yellow"], queries = ["YellOw"]
#  Output: ["yellow"]
#  
#   
#  Constraints:
#  
#  1 <= wordlist.length, queries.length <= 5000
#  1 <= wordlist[i].length, queries[i].length <= 7
#  wordlist[i] and queries[i] consist only of only English letters.
#  
#  

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        words = set(wordlist)
        cap = {}
        vowel = {}
        for word in wordlist:
            lower = word.lower()
            wild_lower = self.to_wild_lower(word)
            if lower not in cap:
                cap[lower] = word

            if wild_lower not in vowel:
                vowel[wild_lower] = word

        res = []
        for q in queries:
            if q in words:
                res.append(q)
                continue

            lower = q.lower()
            wild_lower = self.to_wild_lower(q)

            if lower in cap:
                res.append(cap[lower])
            elif wild_lower in vowel:
                res.append(vowel[wild_lower])
            else:
                res.append('')
        return res

    def to_wild_lower(self, word: str) -> str:
        res = ''
        for ch in word:
            res += ('#' if ch.lower() in 'aeiou' else ch.lower())
 
        return res