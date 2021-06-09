/*
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
Return the number of negative numbers in grid.

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
*/

class Solution
{
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int count = 0;
        int top = 0, left = grid[0].size() - 1;
        while(top < grid.size() && left >= 0)
        {
            if(grid[top][left] < 0)
            {
                count += grid.size() - top;
                left --;
                continue;
            }
            top++;
        }
        return count;
    }
};
