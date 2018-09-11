// two pointers
class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        if (size < 3)
        {
            return 0;
        }

        int left = 0;
        int right = size - 1;
        int left_max = height[left];
        int right_max = height[right];

        int result = 0;
        while(left <= right)
        {
            if (left_max < right_max)
            {
                if (height[left] < left_max)
                {
                    result +=  (left_max - height[left]);
                }

                left_max = max(left_max, height[left]);
                left++;
            }
            else
            {
                if (height[right] < right_max)
                {
                    result += (right_max - height[right]);
                }

                right_max = max(right_max, height[right]);
                right--;
            }
        }
        
        return result;
    }
};


//scan twice
class Solution2 {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        if (size < 3)
        {
            return 0;
        }

        vector<int> left_maxes(size);
        vector<int> right_maxes(size);

        //scan left to right
        int current_max = -1;
        for (auto i = 0; i < size; ++i)
        {
            current_max = max(current_max, height[i]);
            left_maxes[i] = current_max;
        }

        //scan right to left
        current_max = INT_MIN;
        for (auto i = size - 1; i >= 0; --i)
        {
            current_max = max(current_max, height[i]);
            right_maxes[i] = current_max;
        }

        int result = 0;
        for (auto i = 1; i < size - 1; ++i)
        {
            int bound = min(left_maxes[i], right_maxes[i]);
            if (bound > height[i])
            {
                result += (bound - height[i]);
            }
        }

        return result;
    }
};
