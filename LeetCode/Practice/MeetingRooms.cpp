/*
 * Given an array of meeting time intervals where intervals[i] = [starti, endi],
 * determine if a person could attend all meetings.



Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 */




class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        if(intervals.size()==0)
            return true;
        sort(intervals.begin(), intervals.end());
        for (size_t i = 0; i < intervals.size() - 1; i++)
            if (intervals[i][1] > intervals[i + 1][0])
                return false;
        return true;
    }
};
