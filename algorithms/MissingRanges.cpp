// Source : https://leetcode.com/problems/missing-ranges/
// Date   : 2016/10/11

// Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        if(nums.empty())
        {
          ranges.push_back(getRange(lower, upper));
          return ranges;
        }
        if(lower < nums[0])
        {
          ranges.push_back(getRange(lower, nums[0]-1));
        }
        for(int i = 0; i < nums.size()-1; ++i)
        {
          if(nums[i]+1 != nums[i+1])
            ranges.push_back(getRange(nums[i]+1, nums[i+1]-1));
        }
        if(upper > nums[nums.size()-1])
          ranges.push_back(getRange(nums[nums.size()-1]+1, upper));
    }
    
    string getRange(int lower, int upper)
    {
      if(lower == upper)
        return to_string(lower);
      else
        return to_string(lower) + "->" + to_string(upper);
    }
};
