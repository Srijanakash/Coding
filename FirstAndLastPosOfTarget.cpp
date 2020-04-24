/*
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int index=0,lIndex=-1,rIndex=-1,l=0,r=nums.size()-1;
        vector<int>res;
        if(nums.size()==0)
            return {-1,-1};
        if(target<nums[0] ||  target>nums[nums.size()-1])
            return {-1,-1};
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                lIndex=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==target)
            {
                rIndex=i;
                break;
            }
        }
        res.push_back(lIndex);
        res.push_back(rIndex);
        return res;
    }
};
