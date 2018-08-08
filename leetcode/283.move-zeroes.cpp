class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int slow = 0;
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] != 0){
                int tmp = nums[slow];
                nums[slow] = nums[i];
                nums[i] = tmp;
                slow++;
            }
        }
    }
};
