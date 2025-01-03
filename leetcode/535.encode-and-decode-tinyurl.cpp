//  Tag: Hash Table, String, Design, Hash Function
//  Time: O(1)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Note: This is a companion problem to the System Design problem: Design TinyURL.
//  TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.
//  There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
//  Implement the Solution class:
//  
//  Solution() Initializes the object of the system.
//  String encode(String longUrl) Returns a tiny URL for the given longUrl.
//  String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.
//  
//   
//  Example 1:
//  
//  Input: url = "https://leetcode.com/problems/design-tinyurl"
//  Output: "https://leetcode.com/problems/design-tinyurl"
//  
//  Explanation:
//  Solution obj = new Solution();
//  string tiny = obj.encode(url); // returns the encoded tiny url.
//  string ans = obj.decode(tiny); // returns the original url after decoding it.
//  
//   
//  Constraints:
//  
//  1 <= url.length <= 104
//  url is guranteed to be a valid URL.
//  
//  

class Solution {
public:
    unordered_map<string, string> code2url;
    unordered_map<string, string> url2code;
    // Encodes a URL to a shortened URL.

    string gen(int length) {
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
       
        string code = "";

        for (int i = 0; i < length; i++) {
            int index = rand() % alphabet.size();
            code += alphabet[index];
        }

        return code;
    } 

    string encode(string longUrl) {
        
        while (url2code.count(longUrl) == 0) {
            string code = gen(6);
            if (code2url.count(code) == 0) {
                url2code[longUrl] = code;
                code2url[code] = longUrl;
            }
        }

        return "http://tinyurl.com/" + url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.size() - 6);
        return code2url[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));