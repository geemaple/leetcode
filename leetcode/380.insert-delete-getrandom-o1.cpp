class RandomizedSet {
private:
    vector<int> list;
    unordered_map<int, int> map;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()){
            return false;
        }
        
        list.push_back(val);
        map[val] = list.size() - 1;
    
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end()){
            return false;
        }
        
        int index = map[val];
        int last = list.back();
        map[last] = index;
        
        // switch last and index, and pop last
        list[index] = last;
        list.pop_back();
        
        map.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */