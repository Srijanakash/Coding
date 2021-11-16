/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/




class Solution 
{
    int findTarget(vector<int>&nums, int target, bool isFirst)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                if(isFirst)
                {
                    if(mid == low || nums[mid-1] != target)
                        return mid;
                    high = mid - 1;
                }
                else
                {
                    if(mid == high || nums[mid+1] != target)
                        return mid;
                    low = mid + 1;
                }
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int firstOccurence = findTarget(nums, target, true);
        if(firstOccurence == -1)
            return {-1, -1};
        int lastOccurence = findTarget(nums, target, false);
        return {firstOccurence, lastOccurence};
    }
};