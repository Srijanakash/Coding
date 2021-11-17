/*
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
*/




class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                count0++;
            if(nums[i] == 1)
                count1++;
            if(nums[i] == 2)
                count2++;
        }
        int index = 0;
        for(int i=0;i<count0;i++)
            nums[index++] = 0;
        for(int i=0;i<count1;i++)
            nums[index++] = 1;
        for(int i=0;i<count2;i++)
            nums[index++] = 2;
    }
};