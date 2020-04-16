/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
*/

class Solution 
{
    bool isCyclic(vector<int> g[],int n)
    {
        queue<int>q;
        vector<int>indegree;
        indegree.assign(n,0);
        for(int i=0;i<n;i++)
            for(auto j=g[i].begin();j!=g[i].end();j++)
                indegree[*j]++;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        int cnt=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto i=g[temp].begin();i!=g[temp].end();i++)
                if(--indegree[*i]==0)
                    q.push(*i);
            cnt++;
        }
        if(cnt!=n)
            return true;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) 
    {
        vector<int>g[numCourses];
        for(int i=0;i<pre.size();i++)
            g[pre[i][0]].push_back(pre[i][1]);
        if(isCyclic(g,numCourses))
            return false;
        return true;
    }
};
