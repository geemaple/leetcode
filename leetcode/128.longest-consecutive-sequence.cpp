//  Tag: Array, Hash Table, Union Find
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//  You must write an algorithm that runs in O(n) time.
//   
//  Example 1:
//  
//  Input: nums = [100,4,200,1,3,2]
//  Output: 4
//  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//  
//  Example 2:
//  
//  Input: nums = [0,3,7,2,5,8,4,6,0,1]
//  Output: 9
//  
//   
//  Constraints:
//  
//  0 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  
//  

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int res = 0;
        for (int x: num_set) {
            if (num_set.count(x - 1) == 0) {
                int y = x + 1;
                while (num_set.count(y) > 0) {
                    y += 1;
                }

                res = max(res, y - x);
            }
        }

        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0;

        for (int x: nums) {
            if (count[x] == 0) {
                int total = count[x - 1] + 1 + count[x + 1];
                count[x] = total;
                // update left right boarder
                count[x - count[x - 1]] = total;
                count[x + count[x + 1]] = total;

                res = max(res, total);
            }
        }

        return res;
    }
};

class UnionFind {
    std::vector<int> table; 
public:
    std::vector<int> count;
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            table.push_back(i);
            count.push_back(1);
        }
    }

    void connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            table[root_a] = root_b;
            count[root_b] += count[root_a];
        }
    }

    int find(int x) {
        if (table[x] == x) {
            return x;
        }
        table[x] = find(table[x]);
        return table[x];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mapping;
        for(int i = 0; i < n; i++) {
            mapping[nums[i]] = i;
        }

        UnionFind uf = UnionFind(n);
        for (auto it = mapping.begin(); it != mapping.end(); it++) {
            int x = it->first;
            if (mapping.count(x + 1) > 0) {
                uf.connect(it->second, mapping[x + 1]);
            }
        }

        int res = 0;
        for (auto x: uf.count) {
            res = max(res, x);
        }

        return res;
    }
};