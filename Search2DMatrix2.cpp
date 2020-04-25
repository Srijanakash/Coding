/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(matrix.size()==0)
            return false;
        if(matrix[0].size()==0)
            return false;
        int x=matrix.size()-1,y=0;
        while(x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size())
        {
            if(matrix[x][y]==target)
                return true;
            if(matrix[x][y]>target)
                x--;
            else
                y++;
        }
        return false;
    }
};
