// Source : https://leetcode.com/problems/majority-element/
// Date   : 2016-10-01

// Given an array of size n, find the majority element. The majority element 
// is the element that appears more than ⌊ n/2 ⌋ times.
// 
// You may assume that the array is non-empty and the majority element always exist in the array.

// Moore Voting Algorithm
// Refer to: 
// http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        int cnt = 0;
        for(int i=0; i<nums.size(); ++i){
            if(cnt == 0)
            {
                majority = nums[i];
                ++cnt;
            }
            else
            {
                majority == nums[i] ? ++cnt : --cnt;
                if (cnt >= nums.size()/2) 
                    return majority;
            }
        }
        return majority;
    }
};
