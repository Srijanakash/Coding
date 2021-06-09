/*
 * Given an array nums of non-negative integers, return an array consisting of all the even elements of nums, followed by all the odd elements of nums.

You may return any answer array that satisfies this condition.



Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */



class Solution
{
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        priority_queue<int> pqEven, pqOdd;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
                pqEven.push(nums[i]);
            else
                pqOdd.push(nums[i]);
        }
        vector<int>res;
        while(!pqEven.empty())
        {
            res.push_back(pqEven.top());
            pqEven.pop();
        }
        while(!pqOdd.empty())
        {
            res.push_back(pqOdd.top());
            pqOdd.pop();
        }
        return res;
    }
};