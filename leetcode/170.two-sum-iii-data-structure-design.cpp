class TwoSum {
private:
    unordered_map<int, int> table;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        table[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
    
        for (auto it: table){
            
            int count = table[value - it.first];
            if (count > 1 || (count == 1 && it.first != value - it.first))
            {
                return true;
            }
        }
        
        return false;
    }
};