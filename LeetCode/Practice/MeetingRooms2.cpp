/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
*/




class Solution 
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        if(intervals.size() == 0)
            return 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i=1; i<n; i++)
        {
            int t = pq.top();
            if(intervals[i][0]>=t)
                pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};
