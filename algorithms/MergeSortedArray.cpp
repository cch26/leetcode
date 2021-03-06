// Source : https://leetcode.com/problems/merge-sorted-array/
// Date   : 2016-09-30

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n)
// to hold additional elements from nums2. The number of elements initialized in nums1 and nums2
// are m and n respectively.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int index1 = m-1;
        int index2 = n-1;
        int i = m+n-1;
        for(; index1>=0 && index2>=0; --i)
        {
            if(nums1[index1] > nums2[index2])
                nums1[i] = nums1[index1--];
            else
                nums1[i] = nums2[index2--];
        }
        while(index2 >= 0)
            nums1[i--] = nums2[index2--];
    }
};
