/*
In an N by N square grid, each cell is either empty (0) or blocked (1).
A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:
Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

Example 1:

Input: [[0,1],[1,0]]

Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

*/

class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        int count=0;
        int row[]={-1,-1,-1,1,1,1,0,0},col[]={-1,0,1,-1,0,1,-1,1};
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=0;
        while(!q.empty())
        {
            int queueSize=q.size();
            ans++;
            while(queueSize>0)
            {
                queueSize--;
                int x=q.front().first,y=q.front().second;
                q.pop();
                if(x==n-1 && y==n-1)
                    return ans;
                for(int i=0;i<8;i++)
                {
                    int xx=x+row[i],yy=y+col[i];
                    if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==0)
                    {
                        grid[xx][yy]=1;
                        q.push({xx,yy});
                    }
                }
            }
        }
        return -1;
    }
};
