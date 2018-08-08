class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size() - 1;

        vector<int> res(2, 0);

        while(left < right)
        {
            if(numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else if(numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            }
        }

        return res;
    }
};
