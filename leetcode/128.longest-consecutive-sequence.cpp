class UnionFind {
private:
    vector<int> table;
public:
    UnionFind(int n){
        table = vector<int>(n);
        for (auto i = 0; i < n; ++i){
            table[i] = i;
        }
    }
    
    int find(int x){
        if (table[x] == x){
            return x;
        }
        
        return table[x] = find(table[x]);
    }
    
    void connect(int x, int y){
        
        int superX = find(x);
        int superY = find(y);
        
        if (superX != superY){
            table[superX] = superY;
        }
    }
    
    int maxconnect(){
        unordered_map<int, int> map;
        int ans = 0;
        for (auto i = 0; i < table.size(); ++i){
            map[find(i)] += 1;
            ans = max(ans, map[table[i]]);
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> map;
        for (auto i = 0; i < nums.size(); ++i){
            map[nums[i]] = i;
        }
        
        UnionFind uf = UnionFind(nums.size());
        for (auto i = 0; i < nums.size(); ++i){
            int num = nums[i];
            
            if (map[num] != i) {
                continue;
            }
            
            if (map.count(num - 1) > 0){
                uf.connect(i, map[num - 1]);
            }
        }
        
        return uf.maxconnect();
        
    }

    int longestConsecutive2(vector<int>& nums) {
        
        unordered_set<int> set;
        for(auto n: nums){
            set.insert(n);
        }
        
        int longest = 0;
        for (auto n: set){

            // has a previous small head
            if (set.count(n - 1) > 0){
                continue;
            }

            int currentNum = n;
            int length = 1;

            while (set.count(currentNum + 1) > 0){
                currentNum += 1;
                length += 1;
            }

            longest = max(length, longest);
        }

        return longest;

    }
};