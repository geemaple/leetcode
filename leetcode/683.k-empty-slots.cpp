
// O(NLogN) with set(red-black tree)
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        
        if (flowers.size() == 0)
        {
            return 0;
        }
        
        set<int> table;
        table.insert(flowers[0]);
        
        for (auto i = 1; i < flowers.size(); ++i)
        {
            auto lower = table.lower_bound(flowers[i]);
            if (lower != table.begin())
            {
               lower--;
            }
    
            auto upper = table.upper_bound(flowers[i]);
            
            
            if (lower != table.end() && flowers[i] - *lower == k + 1)
            {
                return i + 1;
            }
            
            if (upper != table.end() && *upper - flowers[i] == k + 1)
            {
                return i + 1;
            }
            
            table.insert(flowers[i]);
        }
        
        return -1;
    }
};