/*
 * Given a rows x cols binary matrix filled with 0's and 1's,
 * find the largest rectangle containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 */




class Solution
{
    int areaOfHistogram(vector<int> &hist, int n)
    {
        stack<int> s;
        int maxArea = 0, topOfStack, areaWithTop, i = 0;
        while (i < n)
        {
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);
            else
            {
                topOfStack = s.top();
                s.pop();
                areaWithTop = hist[topOfStack] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, areaWithTop);
            }
        }
        while (!s.empty())
        {
            topOfStack = s.top();
            s.pop();
            areaWithTop = hist[topOfStack] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithTop);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if(matrix.size()==0)
            return 0;
        int maxArea = 0;
        int n = matrix[0].size();
        vector<int>dp (n, 0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                dp[j] = matrix[i][j] == '1'? dp[j] + 1 : 0;
            maxArea = max(maxArea, areaOfHistogram(dp, n));
        }
        return maxArea;
    }
};
