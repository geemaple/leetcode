//  Tag: Array, Hash Table, Two Pointers, Sorting, Counting
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//  As the answer can be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
//  Output: 20
//  Explanation: 
//  Enumerating by the values (arr[i], arr[j], arr[k]):
//  (1, 2, 5) occurs 8 times;
//  (1, 3, 4) occurs 8 times;
//  (2, 2, 4) occurs 2 times;
//  (2, 3, 3) occurs 2 times.
//  
//  Example 2:
//  
//  Input: arr = [1,1,2,2,2,2], target = 5
//  Output: 12
//  Explanation: 
//  arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
//  We choose one 1 from [1,1] in 2 ways,
//  and two 2s from [2,2,2,2] in 6 ways.
//  
//  Example 3:
//  
//  Input: arr = [2,1,3], target = 6
//  Output: 1
//  Explanation: (1, 2, 3) occured one time in the array so we return 1.
//  
//   
//  Constraints:
//  
//  3 <= arr.length <= 3000
//  0 <= arr[i] <= 100
//  0 <= target <= 300
//  
//  

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long long> counter;
        for (auto &x: arr) {
            counter[x] += 1;
        }
        int mod = 1e9 + 7;
        int res = 0;
        for (auto &[first, c1]: counter) {
            for (auto &[second, c2]: counter) {
                int last = target - first - second;
                if (counter.find(last) == counter.end()) {
                    continue;
                }

                if (first == second && second == last) {
                    res = (res + c1 * (c1 - 1) * (c1 - 2) / 6) % mod;
                } else if (first == second && second != last) {
                    res = (res + c1 * (c1 - 1) / 2 * counter[last]) % mod;
                } else if (first < second && second < last) {
                    res = (res + c1 * c2 * counter[last]) % mod;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, long long> counter;
        sort(arr.begin(), arr.end());
        for (auto &x: arr) {
            counter[x] += 1;
        }
        int mod = 1e9 + 7;
        int res = 0;
        for (int k = 0; k < n; k++) {
            if (k > 0 && arr[k] == arr[k - 1]) {
                continue;
            }

            int l = k + 1;
            int r = n - 1;
            while (l <= r) {
                int tmp = arr[k] + arr[l] + arr[r];
                if (tmp == target) {
                    if (arr[k] == arr[r]) {
                        res = (res + counter[arr[k]] * (counter[arr[k]] - 1) * (counter[arr[k]] - 2) / 6) % mod;
                    } else if (arr[k] == arr[l]) {
                        res = (res + counter[arr[k]] * (counter[arr[k]] - 1) / 2 * counter[arr[r]]) % mod;
                    } else if (arr[l] == arr[r]) {
                        res = (res + counter[arr[l]] * (counter[arr[l]] - 1) / 2 * counter[arr[k]]) % mod;
                    } else {
                        res = (res + counter[arr[k]] * counter[arr[l]] * counter[arr[r]]) % mod;
                    }

                    while (l < r && arr[l] == arr[l + 1]) {
                        l += 1;
                    }

                    while (l <= r && arr[r] == arr[r - 1]) {
                        r -= 1;
                    }
                    l += 1;
                    r -= 1;

                } else if (tmp > target) {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }

        return res;
    }
};