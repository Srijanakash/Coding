/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return nums.size();
        unordered_set<int>us,vis;
        for(int i=0;i<nums.size();i++)
            us.insert(nums[i]);
        int globalCount=0,localCount;
        for(auto i=us.begin();i!=us.end();i++)
        {
            if(vis.find(*i)==vis.end())
            {
                localCount=0;
                stack<int>s;
                s.push(*i);
                while(!s.empty())
                {
                    
                    int temp=s.top();
                    s.pop();
                    vis.insert(temp);
                    localCount++;
                    if(vis.find(temp+1)==vis.end() && us.find(temp+1)!=us.end())
                        s.push(temp+1);
                    if(vis.find(temp-1)==vis.end() && us.find(temp-1)!=us.end())
                        s.push(temp-1);
                }
                globalCount=max(localCount,globalCount);
            }
        }
        return globalCount;
    }
};
