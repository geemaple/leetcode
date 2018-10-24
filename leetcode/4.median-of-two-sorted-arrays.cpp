class Solution {
private:
    int kthNumber(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int kth){
        
        if (start1 >= nums1.size())
        {
            return nums2[start2 + kth - 1];
        }
        
        if (start2 >= nums2.size()){
            return nums1[start1 + kth - 1];
        }
        
        if (kth == 1)
        {
            return min(nums1[start1], nums2[start2]);
        }
        
        int left = INT_MAX;
        if (start1 + kth / 2 - 1 < nums1.size())
        {
            left = nums1[start1 + kth / 2 - 1];
        }
        
        int right = INT_MAX;
        if (start2 + kth / 2 - 1 < nums2.size())
        {
            right = nums2[start2 + kth / 2 - 1];
        }
        
        if (left < right){
            return kthNumber(nums1, start1 + kth / 2, nums2, start2, kth - kth / 2);
        }else{
            return kthNumber(nums1, start1, nums2, start2 + kth / 2, kth - kth / 2);
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        if (k % 2 == 0){
            return double(kthNumber(nums1, 0, nums2, 0, k / 2) + kthNumber(nums1, 0, nums2, 0, k / 2 + 1)) / 2.0;
        }else{
            return double(kthNumber(nums1, 0, nums2, 0, k / 2 + 1));
        }
    }
};