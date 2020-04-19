/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, 
and replace the last element with -1.
After doing so, return the array.

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
*/

class Solution 
{
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int n=arr.size();
        stack<int>s;
        for(int i=n-1;i>0;i--)
        {
            if(i==n-1)
                s.push(arr[i]);
            else
            {
                if(arr[i]>s.top())
                    s.push(arr[i]);
                else
                    s.push(s.top());
            }
        }
        vector<int>res;
        for(int i=0;i<n-1;i++)
        {
            res.push_back(s.top());
            s.pop();
        }
        res.push_back(-1);
        return res;
    }
};
