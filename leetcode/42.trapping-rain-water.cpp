// two pointers
class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() < 3)
        {
            return 0;
        }
        
        int size = height.size();
        
        int left_max = height[0];
        int right_max = height[size - 1];
        
        int start = 1;
        int end = size - 2;
        
        int water = 0;
        while(start <= end)
        {
            if (left_max <= right_max)
            {
                water += max(0, left_max - height[start]);
                left_max = max(left_max, height[start]);
                start++;
            }
            else
            {
                water += max(0, right_max - height[end]);
                right_max = max(right_max, height[end]);
                end--;
            }
        }
        
        return water;
    }
};

//scan twice
class Solution2 {
public:
    int trap(vector<int>& height) {

        if (height.size() < 3)
        {
            return 0;
        }

        int size = height.size();
        vector<int> left_max(size);
        vector<int> right_max(size);

        //scan left to right
        int current_max = INT_MIN;
        for (auto i = 0; i < size; ++i)
        {
            current_max = max(current_max, height[i]);
            left_max[i] = current_max;
        }

        //scan right to left
        current_max = INT_MIN;
        for (auto i = size - 1; i >= 0; --i)
        {
            current_max = max(current_max, height[i]);
            right_max[i] = current_max;
        }

        int result = 0;
        for (auto i = 1; i < size - 1; ++i)
        {
            int bound = min(left_max[i], right_max[i]);
            if (bound > height[i])
            {
                result += (bound - height[i]);
            }
        }

        return result;
    }
};
