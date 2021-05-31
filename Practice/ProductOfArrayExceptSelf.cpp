/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] 
is equal to the product of all the elements of nums except nums[i].
Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix 
or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int length = nums.size();
        vector<int>answer;
        answer.assign(length,0);
        answer[0] = 1;
        for (int i = 1; i < length; i++)
            answer[i] = nums[i - 1] * answer[i - 1];
        int R = 1;
        for (int i = length - 1; i >= 0; i--) 
        {
            answer[i] = answer[i] * R;
            R *= nums[i];
        }
        return answer;
    }
};
