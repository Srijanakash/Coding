/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
*/

class Solution 
{
    int bfs(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        int area=1;
        int rowNum[]={1,-1,0,0};
        int colNum[]={0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=2;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xx=x+rowNum[i],yy=y+colNum[i];
                if(xx>=0 && yy>=0 && xx<m && yy<n && grid[xx][yy]==1)
                {
                    q.push({xx,yy});
                    grid[xx][yy]=2;
                    area++;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        if(m==0)
            return 0;
        int n=grid[0].size();
        int maxArea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int res=0;
                if(grid[i][j]==1)
                    res=bfs(grid,i,j,m,n);
                maxArea=max(maxArea,res);
            }
        }
        return maxArea;
    }
};
