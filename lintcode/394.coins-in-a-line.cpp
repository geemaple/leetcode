// f[i] = (f[i - 1] == false or f[i - 2] == false) 
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here

        if (n == 0)
        {
            return false;
        }

        if (n == 1 || n == 2)
        {
            return true;
        }

        vector<bool> table(n + 1, false);
        table[0] = false;
        table[1] = table[2] = true;
        
        for(auto i = 3; i <=n; ++i)
        {
            table[i] = (!table[i - 1] || !table[i - 2]);
        }

        return table[n];
    }
};