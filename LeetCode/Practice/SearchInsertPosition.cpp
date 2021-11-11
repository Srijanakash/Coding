/*
 * Given a sorted array of distinct integers and a target value,
 *  return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
 */




class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if(target <= nums[0])
            return 0;
        if(target > nums[nums.size() - 1])
            return nums.size();
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(target == nums[mid])
                return mid;
            if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
