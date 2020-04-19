/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d 
in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n <4)
            return ret;
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int left = 0, right = 0, target_3Sum = 0, target_2Sum = 0;
        for (i = 0; i < n-3; ++i)
        {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            target_3Sum = target - nums[i];
            for (j = i + 1; j < n-2; ++j)
            {
                if (j != (i+1) && nums[j] == nums[j-1])
                    continue;
                target_2Sum = target_3Sum - nums[j];
                left = j + 1;
                right = n - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] == target_2Sum)
                    {
                        ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while (left < right && nums[left+1] == nums[left])
                            left++;
                        while (left < right && nums[right-1] == nums[right])
                            right--;
                        left++;
                        right--;
                    }
                    else if (nums[left] + nums[right] < target_2Sum)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ret;
    }
};
