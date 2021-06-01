/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int>s;
        int result=0,left,res,curr;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && heights[i]<heights[s.top()])
            {
                curr=s.top();
                s.pop();
                left=s.empty()?0:s.top()+1;
                res=heights[curr]*(i-left);
				result=max(result,res);
            }
            s.push(i);
        }
        while(!s.empty())
		{
			curr=s.top();
			s.pop();
			left=s.empty() ? 0:s.top()+1;
			res=heights[curr]*(heights.size()-left);
			result=max(result,res);
		}
		return result;
    }
};
