//  Tag: Math, Design, Segment Tree
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Write an API that generates fancy sequences using the append, addAll, and multAll operations.
//  Implement the Fancy class:
//  
//  Fancy() Initializes the object with an empty sequence.
//  void append(val) Appends an integer val to the end of the sequence.
//  void addAll(inc) Increments all existing values in the sequence by an integer inc.
//  void multAll(m) Multiplies all existing values in the sequence by an integer m.
//  int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
//  
//   
//  Example 1:
//  
//  Input
//  ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
//  [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
//  Output
//  [null, null, null, null, null, 10, null, null, null, 26, 34, 20]
//  
//  Explanation
//  Fancy fancy = new Fancy();
//  fancy.append(2);   // fancy sequence: [2]
//  fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
//  fancy.append(7);   // fancy sequence: [5, 7]
//  fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
//  fancy.getIndex(0); // return 10
//  fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
//  fancy.append(10);  // fancy sequence: [13, 17, 10]
//  fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
//  fancy.getIndex(0); // return 26
//  fancy.getIndex(1); // return 34
//  fancy.getIndex(2); // return 20
//  
//   
//  Constraints:
//  
//  1 <= val, inc, m <= 100
//  0 <= idx <= 105
//  At most 105 calls total will be made to append, addAll, multAll, and getIndex.
//  
//  

class Fancy {
public:
    long long mul = 1;
    long long inc = 0;
    const long long mod = 1e9 + 7;

    vector<long long> nums;
    vector<long long> v_muls;
    vector<long long> v_incs;
    Fancy() {
        
    }
    
    void append(int val) {
        nums.push_back(val);
        v_muls.push_back(mul);
        v_incs.push_back(inc);
    }
    
    void addAll(int i) {
        inc = (inc + i) % mod;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        inc = (inc * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        
        long long ratio = (mul * modInverse(v_muls[idx])) % mod;
        long long res = (nums[idx] * ratio) % mod;
        res = (res + inc) % mod;
        long long sub = (v_incs[idx] * ratio) % mod;
        res = (res - sub + mod) % mod;
        
        return res;
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, mod - 2);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */