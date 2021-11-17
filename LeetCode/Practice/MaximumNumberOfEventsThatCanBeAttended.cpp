/*
Given an array of events where events[i] = [startDayi, endDayi]. 
Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. 
Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
Example 3:

Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4
Example 4:

Input: events = [[1,100000]]
Output: 1
Example 5:

Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7
*/




class Solution 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n=events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int ans=0;
        int i=0;
        for(int d = 1; d <= 100000; d++)
        {
            while(!pq.empty() && pq.top() < d)
                pq.pop();
            while(i < n && events[i][0] == d)
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
            if(pq.empty() && i==n)
                break;
        }
        return ans;
    }
};