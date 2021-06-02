/*
 * Given an array nums of positive integers, let minDigitSum be the sum of the digits of the minimal element of nums.

Return 0 if minDigitSum is odd, otherwise return 1.



Example 1:

Input: nums = [34,23,1,24,75,33,54,8]
Output: 0
Explanation:
The minimal element is 1, and the sum of those digits is minDigitSum = 1 which is odd, so the answer is 0.
Example 2:

Input: nums = [99,77,33,66,55]
Output: 1
Explanation:
The minimal element is 33, and the sum of those digits is minDigitSum = 3 + 3 = 6 which is even, so the answer is 1.
 */



class Solution
{
public:
    int sumOfDigits(vector<int>& nums)
    {
        int minElement = *min_element(nums.begin(), nums.end());
        int sumOfDigits = 0;
        while(minElement > 0)
        {
            sumOfDigits += minElement%10;
            minElement /= 10;
        }
        return (sumOfDigits+1)%2;
    }
};