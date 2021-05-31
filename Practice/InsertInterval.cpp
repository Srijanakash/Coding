//
// Created by srija on 31-05-2021.
//

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        // Edge Case 1: newInterval is less than starting interval
        if(newInterval[1] < intervals[0][0])
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        // Edge Case 2: newInterval is greater than the last interval
        if(newInterval[0] > intervals[intervals.size() - 1][1])
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> res;
        for(int i=0; i<intervals.size(); i++)
        {
            if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1])
                res.push_back(intervals[i]);
            else
            {
                int start = min(intervals[i][0], newInterval[0]), end;
                while(intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
                    i++;
                end = max(intervals[i-1][1], newInterval[1]);
                res.push_back({start, end});
            }
        }
        return res;
    }
};


