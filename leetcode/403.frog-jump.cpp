class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        if (stones.size() == 0){
            return true;
        }
        
        // key = kth stone, available jump distances at kth stone
        unordered_map<int, unordered_set<int>> map;
        for(auto i = 0; i < stones.size(); ++i){
            map[stones[i]] = unordered_set<int>();
        }
        
        map[stones[0]].insert(1);
        
        for (auto i = 0; i< stones.size(); ++i){
            int kth = stones[i];
            for (int step: map[kth]){
                int reach = step + kth;
                
                if (reach == stones[stones.size() - 1]){
                    return true;
                }
                
                if (map.count(reach) > 0){
                    if (step - 1 > 0){
                        map[reach].insert(step - 1);
                    }
                    map[reach].insert(step);
                    map[reach].insert(step + 1);
                }
                
            }
        }
        
        return false;
    }
};