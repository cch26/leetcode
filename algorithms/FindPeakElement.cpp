// Source : https://leetcode.com/problems/find-peak-element/
// Date : 2016/10/12

// A peak element is an element that is greater than its neighbors.
// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that num[-1] = num[n] = -∞.
// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
// Note:
// Your solution should be in logarithmic complexity.

// Binary Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1]))
                return mid;
            if(nums[mid]<nums[mid+1]) // mid==0 is ok
                left = mid+1;
            else
                right = mid-1;
        }
        return left;
    }
};

// Sequential Search
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); ++i)
        {
            if(num[i] < num[i-1])
            {
                return i-1;
            }
        }
        return num.size()-1;
    }
};
