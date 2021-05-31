/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if (nums.empty()) 
            return result;
        int n_size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n_size; ++i) 
        {
            if (nums[i] > 0) 
                break;
            if (i > 0 and nums[i] == nums[i-1]) 
                continue;
            int left = i+1, right = n_size - 1;
            while (left < right) 
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) 
                    left++;
                else if (sum > 0) 
                    right--;
                else 
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    int last_left = nums[left], last_right = nums[right];
                    while (left < right && nums[left] == last_left) 
                        left++;
                    while (left < right && nums[right] == last_right) 
                        right--;
                }
            }
        }
        return result;
    }
};
