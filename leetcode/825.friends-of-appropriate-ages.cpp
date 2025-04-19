//  Tag: Array, Two Pointers, Binary Search, Sorting
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
//  A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
//  
//  age[y] <= 0.5 * age[x] + 7
//  age[y] > age[x]
//  age[y] > 100 && age[x] < 100
//  
//  Otherwise, x will send a friend request to y.
//  Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
//  Return the total number of friend requests made.
//   
//  Example 1:
//  
//  Input: ages = [16,16]
//  Output: 2
//  Explanation: 2 people friend request each other.
//  
//  Example 2:
//  
//  Input: ages = [16,17,18]
//  Output: 2
//  Explanation: Friend requests are made 17 -> 16, 18 -> 17.
//  
//  Example 3:
//  
//  Input: ages = [20,30,100,110,120]
//  Output: 3
//  Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
//  
//   
//  Constraints:
//  
//  n == ages.length
//  1 <= n <= 2 * 104
//  1 <= ages[i] <= 120
//  
//  

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> counter(121, 0);
        for (auto &x: ages) {
            counter[x] += 1;
        }
        int res = 0;
        int count = 0;
        int i = 15;
        for (int j = 15; j <= 120; j++) {
            while (i < j / 2 + 8) {
                count -= counter[i];
                i += 1;
            }
            count += counter[j]; 
            res += counter[j] * (count - 1);
        }

        return res;
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> counter(121, 0);
        for (auto &x: ages) {
            counter[x] += 1;
        }
        int res = 0;
        for (int i = 15; i <= 120; i++) {
            for (int j = i / 2 + 8; j <= i; j++) {
                res += counter[i] * (counter[j] - (i == j));
            }
        }

        return res;
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int count = 1;
        int res = 0;
        sort(ages.begin(), ages.end());
        for (int j = n - 1; j >= 0; j--) {
            if (ages[j] < 15) {
                break;
            }

            if (j >= 1 && ages[j] == ages[j - 1]) {
                count += 1;
                continue;
            }

            int k = ages[j] / 2 + 7;
            int i = upper_bound(ages.begin(), ages.end(), k) - ages.begin();
            res += (j - i) * count + count * (count -  1);
            count = 1;
        }

        return res;
    }
};