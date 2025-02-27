//  Tag: String, Binary Search, Sliding Window, Prefix Sum
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
//  You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
//  
//  Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
//  
//  Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
//   
//  Example 1:
//  
//  Input: answerKey = "TTFF", k = 2
//  Output: 4
//  Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
//  There are four consecutive 'T's.
//  
//  Example 2:
//  
//  Input: answerKey = "TFFT", k = 1
//  Output: 3
//  Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
//  Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
//  In both cases, there are three consecutive 'F's.
//  
//  Example 3:
//  
//  Input: answerKey = "TTFTTFTT", k = 1
//  Output: 5
//  Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
//  Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
//  In both cases, there are five consecutive 'T's.
//  
//   
//  Constraints:
//  
//  n == answerKey.length
//  1 <= n <= 5 * 104
//  answerKey[i] is either 'T' or 'F'
//  1 <= k <= n
//  
//  

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
  
        int n = answerKey.size();
        int i = 0;
        vector<int> counter(26, 0);
        int res = 0;
        int maxf = 0;
        
        for (int j = 0; j < n; j++) {
            counter[answerKey[j] - 'A'] += 1;
            maxf = max(maxf, counter[answerKey[j] - 'A']);
            while (j - i + 1 > maxf + k) {
                counter[answerKey[i] - 'A'] -= 1;
                i += 1;
            }
            
            res = max(res, j - i + 1);
        }

        return res;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = find(answerKey, k, 'F');
        int f = find(answerKey, k, 'T');
        return max(t, f);
    }

    int find(const string& answerKey, int k, char mark) {
        int n = answerKey.size();
        int i = 0;
        int count = 0; 
        int res = 0;
        
        for (int j = 0; j < n; j++) {
            count += answerKey[j] == mark;

            while (count > k) {
                count -= answerKey[i] == mark;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};