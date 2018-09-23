class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        
        int ans = 0;
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums_set.count(nums[i]) > 0)
            {
                nums_set.erase(nums[i]);
                int lower = nums[i];
                int upper = nums[i];
                
                // scan lower
                while(lower > INT_MIN && nums_set.count(lower - 1) > 0)
                {
                    nums_set.erase(lower - 1);
                    lower--;
                }
                
                // scan upper
                while(upper < INT_MAX && nums_set.count(upper + 1) > 0)
                {
                    nums_set.erase(upper + 1);
                    upper++;
                }
                
                ans = max(ans, upper - lower + 1);
            }
        }
        
        return ans;
    }
};

class UnoinFind {
    vector<int> table;
    unordered_map<int, int> count;
public:
    UnoinFind(int nums){
        for (auto i = 0; i < nums; ++i)
        {
            table.push_back(i);
            count[i] = 1;
        }
    }

    int find(int a){
        if (table[a] == a)
        {
            return a;
        }

        return table[a] = find(table[a]);
    }

    void connect(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b){
            table[root_a] = root_b;
            count[root_b] += count[root_a];
        }
    }

    int maxGroup()
    {
        int ans = 0;
        for (auto it : count)
        {
            ans = max(ans, it.second);
        }
        return ans;
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapping;
        UnoinFind uf(nums.size());
        for (auto i = 0; i < nums.size(); ++i)
        {
            mapping[nums[i]] = i;
        }

        for (auto i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (mapping[num] != i)
            {
                continue;
            }

            if (mapping.count(num + 1) > 0)
            {
                uf.connect(i, mapping[num + 1]);
            }
        }

        return uf.maxGroup();
    }
};