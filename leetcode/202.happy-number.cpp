// O(N) n = steps to be a happy number
class Solution {
private:
    int digitSquareSum(int n){
        int sum = 0;
        while(n){
            int tmp = n % 10;
            sum += tmp * tmp;
            n = n / 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int res = n;
        while(res != 1){
            if (set.count(res) > 0){
                return false;
            }

            set.insert(res);
            res = digitSquareSum(res);
        }

        return true;
    }
};
