//  Tag: Math, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
//  
//  It has a length of k.
//  It is a divisor of num.
//  
//  Given integers num and k, return the k-beauty of num.
//  Note:
//  
//  Leading zeros are allowed.
//  0 is not a divisor of any value.
//  
//  A substring is a contiguous sequence of characters in a string.
//   
//  Example 1:
//  
//  Input: num = 240, k = 2
//  Output: 2
//  Explanation: The following are the substrings of num of length k:
//  - "24" from "240": 24 is a divisor of 240.
//  - "40" from "240": 40 is a divisor of 240.
//  Therefore, the k-beauty is 2.
//  
//  Example 2:
//  
//  Input: num = 430043, k = 2
//  Output: 2
//  Explanation: The following are the substrings of num of length k:
//  - "43" from "430043": 43 is a divisor of 430043.
//  - "30" from "430043": 30 is not a divisor of 430043.
//  - "00" from "430043": 0 is not a divisor of 430043.
//  - "04" from "430043": 4 is not a divisor of 430043.
//  - "43" from "430043": 43 is a divisor of 430043.
//  Therefore, the k-beauty is 2.
//  
//   
//  Constraints:
//  
//  1 <= num <= 109
//  1 <= k <= num.length (taking num as a string)
//  
//  

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string num_str = to_string(num);
        int n = num_str.size();
        int high = pow(10, k - 1);
        int res = 0;
        int div = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                div -= (num_str[i - k] - '0') * high;
            }

            div = div * 10 + num_str[i] - '0';

            if (i >= k - 1) {
                if (div && num % div == 0) {
                    res += 1;
                }
            }
        }

        return res;
    }
};