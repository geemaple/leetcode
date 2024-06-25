//  Tag: String, Binary Search
//  Time: O(logN + K)
//  Space: O(1)
//  Ref: -
//  Note: Answer | Bruteforce

//  You are given a string, message, and a positive integer, limit.
//  You must split message into one or more parts based on limit. Each resulting part should have the suffix "<a/b>", where "b" is to be replaced with the total number of parts and "a" is to be replaced with the index of the part, starting from 1 and going up to b. Additionally, the length of each resulting part (including its suffix) should be equal to limit, except for the last part whose length can be at most limit.
//  The resulting parts should be formed such that when their suffixes are removed and they are all concatenated in order, they should be equal to message. Also, the result should contain as few parts as possible.
//  Return the parts message would be split into as an array of strings. If it is impossible to split message as required, return an empty array.
//   
//  Example 1:
//  
//  Input: message = "this is really a very awesome message", limit = 9
//  Output: ["thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>"," aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]
//  Explanation:
//  The first 9 parts take 3 characters each from the beginning of message.
//  The next 5 parts take 2 characters each to finish splitting message. 
//  In this example, each part, including the last, has length 9. 
//  It can be shown it is not possible to split message into less than 14 parts.
//  
//  Example 2:
//  
//  Input: message = "short message", limit = 15
//  Output: ["short mess<1/2>","age<2/2>"]
//  Explanation:
//  Under the given constraints, the string can be split into two parts: 
//  - The first part comprises of the first 10 characters, and has a length 15.
//  - The next part comprises of the last 3 characters, and has a length 8.
//  
//   
//  Constraints:
//  
//  1 <= message.length <= 104
//  message consists only of lowercase English letters and ' '.
//  1 <= limit <= 104
//  
//  
class Solution {
public:
    vector<string> splitMessage(string message, int limit) {

        int digit_min = 1;
        int digit_max = limit - 4;

        int digit = -1;
        for (auto i = digit_min; i < digit_max; i++) {
            if (feasible(message, limit, pow(10, i) - 1)) {
                digit = i;
                break;
            }
        }

        if (digit < digit_min) {
            return vector<string>{};
        }

        int start = pow(10, digit - 1);
        int end = pow(10, digit) - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (feasible(message, limit, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return printOut(message, limit, start);
    }

    bool feasible(string message, int limit, int parts) {
        int suffix = 4 + to_string(parts).size();
        int blank = limit - suffix;
        
        int total = 0;
        int num = 9;
        int test = 0;
        while (parts > test + num && blank > 0) {
            total += num * blank;
            test += num;
            num *= 10;
            blank--;
        }
        total += (parts - test) * blank;
        return total >= message.size();
    }

    vector<string> printOut(string message, int limit, int parts) {
        vector<string> res;
        int j = 0;
        for (auto i = 1; i < parts + 1; i++) {
            string suffix = "<" + to_string(i) + "/" + to_string(parts) + ">";
            int offset = limit - suffix.size();
            res.push_back(message.substr(j, offset) + suffix);
            j += offset;
        }

        return res;
    }
};

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int cur = 1;
        int k = 1;
        while (message.size() + (3 + to_string(k).size()) * k + cur > limit * k && 1 + 3 + to_string(k).size() < limit) {
            k += 1;
            cur += to_string(k).size();
        }

        if (1 + 3 + to_string(k).size() >= limit) {
            return vector<string>{};
        }

        return printOut(message, limit, k);
    }

    vector<string> printOut(string message, int limit, int parts) {
        vector<string> res;
        int j = 0;
        for (auto i = 1; i < parts + 1; i++) {
            string suffix = "<" + to_string(i) + "/" + to_string(parts) + ">";
            int offset = limit - suffix.size();
            res.push_back(message.substr(j, offset) + suffix);
            j += offset;
        }

        return res;

    }
};