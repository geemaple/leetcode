class Solution {
private:
    string getRange(long lower, long upper)
    {
        if (lower == upper)
        {
            return to_string(lower);
        }
        else
        {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
    
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> res;
        long newLower = (long)lower - 1;
        long newUpper = (long)upper + 1;
        long tmpLow = newLower;
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] - tmpLow > 1){
                res.push_back(getRange(tmpLow + 1, nums[i] - 1));
            }
            
            tmpLow = nums[i];
        }
        
        if (newUpper - tmpLow > 1)
        {
            res.push_back(getRange(tmpLow + 1, newUpper - 1));
        }
        
        return res;
    }
};