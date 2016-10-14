// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Date   : 2016/10/14

// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// You may assume no duplicate exists in the array.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right && nums[left] >= nums[right]) 
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left])
            {
            // the mininum is in the left part
                right = mid;
            } 
            else
            {
            // the mininum is in the right part
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
