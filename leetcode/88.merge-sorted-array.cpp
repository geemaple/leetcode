class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int k = m + n - 1;

        int left = m - 1;
        int right = n - 1;

        while(left >= 0 && right >= 0)
        {
            if (nums1[left] < nums2[right])
            {
                nums1[k] = nums2[right];
                right--;
            }
            else
            {
                nums1[k] = nums1[left];
                left--;
            }

            k--;
        }

        while (right >= 0)
        {
            nums1[k] = nums2[right];
            right--;
            k--;
        }
    }
};
