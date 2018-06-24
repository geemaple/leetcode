class TwoSum {
private:
    vector<int> list;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        list.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        bool res = false;
        unordered_set<int> set;
        for (int i = 0; i < list.size(); ++i){
            int another = value - list[i];
            if (set.count(another) > 0){
                return true;
            }
            
            set.insert(list[i]);
        }
        
        
        return res;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */