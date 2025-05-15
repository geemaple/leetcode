//  Tag: Hash Table, Math, String, Dynamic Programming, Counting
//  Time: O(LogT)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/4C11rgivbAo

//  You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:
//  
//  Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
//  The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
//  
//  Return the length of the resulting string after exactly t transformations.
//  Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]
//  Output: 7
//  Explanation:
//  
//  
//  First Transformation (t = 1):
//  
//  'a' becomes 'b' as nums[0] == 1
//  'b' becomes 'c' as nums[1] == 1
//  'c' becomes 'd' as nums[2] == 1
//  'y' becomes 'z' as nums[24] == 1
//  'y' becomes 'z' as nums[24] == 1
//  String after the first transformation: "bcdzz"
//  
//  
//  
//  Second Transformation (t = 2):
//  
//  'b' becomes 'c' as nums[1] == 1
//  'c' becomes 'd' as nums[2] == 1
//  'd' becomes 'e' as nums[3] == 1
//  'z' becomes 'ab' as nums[25] == 2
//  'z' becomes 'ab' as nums[25] == 2
//  String after the second transformation: "cdeabab"
//  
//  
//  
//  Final Length of the string: The string is "cdeabab", which has 7 characters.
//  
//  
//  
//  Example 2:
//  
//  Input: s = "azbk", t = 1, nums = [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]
//  Output: 8
//  Explanation:
//  
//  
//  First Transformation (t = 1):
//  
//  'a' becomes 'bc' as nums[0] == 2
//  'z' becomes 'ab' as nums[25] == 2
//  'b' becomes 'cd' as nums[1] == 2
//  'k' becomes 'lm' as nums[10] == 2
//  String after the first transformation: "bcabcdlm"
//  
//  
//  
//  Final Length of the string: The string is "bcabcdlm", which has 8 characters.
//  
//  
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists only of lowercase English letters.
//  1 <= t <= 109
//  nums.length == 26
//  1 <= nums[i] <= 25
//  
//  

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int mod = 1e9 + 7;
        vector<vector<int>> trans(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < nums[i]; j ++) {
                trans[i][(i + j + 1) % 26] = 1;
            }
        }
        
        vector<vector<int>> vec(1, vector<int>(26, 0));
        for (auto &x: s) {
            vec[0][x - 'a'] += 1;
        }

        vector<vector<int>> t_trans = mat_pow(trans, t, mod);
        vector<vector<int>> res = mat_mul(vec, t_trans, mod);

        return accumulate(res[0].begin(), res[0].end(), 0, [&](int a, int b) {
            return (1LL * a + b) % mod;
        });
    }

    vector<vector<int>> mat_mul(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int mod) {
        int n = mat1.size();
        int m = mat2[0].size();
        int c = mat2.size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < c; k++) {
                    res[i][j] = (res[i][j] + 1LL * mat1[i][k] * mat2[k][j]) % mod;
                }
            }
        }

        return res;
    }

    vector<vector<int>> mat_pow(vector<vector<int>> &mat, int power, int mod) {
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (power > 0) {
            if (power % 2 == 1) {
                res = mat_mul(res, mat, mod);
            }

            mat = mat_mul(mat, mat, mod);
            power /= 2;
        }

        return res;
    }
};