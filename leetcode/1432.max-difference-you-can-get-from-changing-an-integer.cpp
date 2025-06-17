//  Tag: Math, Greedy
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/9kBNJ-ZfHAQ

//  You are given an integer num. You will apply the following steps to num two separate times:
//  
//  Pick a digit x (0 <= x <= 9).
//  Pick another digit y (0 <= y <= 9). Note y can be equal to x.
//  Replace all the occurrences of x in the decimal representation of num by y.
//  
//  Let a and b be the two results from applying the operation to num independently.
//  Return the max difference between a and b.
//  Note that neither a nor b may have any leading zeros, and must not be 0.
//   
//  Example 1:
//  
//  Input: num = 555
//  Output: 888
//  Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
//  The second time pick x = 5 and y = 1 and store the new integer in b.
//  We have now a = 999 and b = 111 and max difference = 888
//  
//  Example 2:
//  
//  Input: num = 9
//  Output: 8
//  Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
//  The second time pick x = 9 and y = 1 and store the new integer in b.
//  We have now a = 9 and b = 1 and max difference = 8
//  
//   
//  Constraints:
//  
//  1 <= num <= 108
//  
//  

class Solution {
public:
    int maxDiff(int num) {
        string max_v = to_string(num);
        string min_v = to_string(num);
        for (auto d: max_v) {
            if (d != '9') {
                replace(max_v, d, '9');
                break;
            }
        }

        for (int i = 0; i < min_v.size(); i++) {
            char d = min_v[i];
            if (i == 0) {
                if (d != '1') {
                    replace(min_v, d, '1');
                    break;
                }
            } else {
                if (d != '0' && d != min_v[0]) {
                    replace(min_v, d, '0');
                    break;          
                } 
            }
        }

        return stoi(max_v) - stoi(min_v);
    }

    void replace(string &str, char a, char b) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == a) {
                str[i] = b;
            }
        }
    }
};

class Solution {
public:
    int maxDiff(int num) {
        int max_v = num;
        int min_v = num;
        int first = 0;
        int n = num;
        while (n > 0) {
            first = n % 10;
            n /= 10;
        }

        for (int i = 0; i < 10; i++) {
            int low = 0;
            int high = 0;
            int mul = 1;
            n = num;
            while (n > 0) {
                bool replace = n % 10 == i;
                high += (replace ? 9 : n % 10) * mul;
                low += (replace ? ((n % 10 == first) ? 1 : 0) : n % 10) * mul;
                mul *= 10;
                n /= 10;
            }
            max_v = max(max_v, high);
            if (low > 0) {
                min_v = min(min_v, low);
            }
        }
        return max_v - min_v;
    }
};