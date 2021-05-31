/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.  
If this is impossible, return -1 instead.

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, 
because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

class Solution 
{
    bool isDelim(pair<int,int>x)
    {
        return x.first==-1 && x.second==-1;
    }
    bool checkall(vector<vector<int>>& g,int r,int c)
    {
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(g[i][j]==1)
                    return true;
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& g) 
    {
        int count=0,r=g.size(),c=g[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                if(g[i][j]==2)
                    q.push(make_pair(i,j));
        }
        q.push(make_pair(-1,-1));
        static int rowNum[]={-1,1,0,0};
        static int colNum[]={0,0,-1,1};
        while(!q.empty())
        {
            bool flag=false;
            while(!isDelim(q.front()))
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int xx=x+rowNum[i];
                    int yy=y+colNum[i];
                    if(xx>=0 && yy>=0 && xx<r
                            && yy<c && g[xx][yy]==1)
                    {
                        if (!flag) 
                        {
                            count++; 
                            flag = true;
                        }
                        g[xx][yy]=2;
                        q.push(make_pair(xx,yy));
                    }
                }
            }
            q.pop();
            if (!q.empty())
                q.push(make_pair(-1,-1));
        }
        return (checkall(g,r,c))? -1:count;
    }
};
