/*
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 * The area of an island is the number of cells with a value 1 in the island.
 *
 * Return the maximum area of an island in grid. If there is no island, return 0.
 *
 * Example 1:
 * Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected 4-directionally.
 *
 * Example 2:
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 */


class Solution
{
    int findArea(vector<vector<int>>& grid, int m, int n, int x, int y)
    {
        queue<pair<int, int>> q;
        int area = 1;
        q.push({x, y});
        grid[x][y] = 2;
        int row[] = {-1, 1, 0, 0}, col[] = {0, 0, 1, -1};
        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int xx = x + row[i], yy = y + col[i];
                if(xx >= 0 && yy >= 0 && xx < m && yy < n && grid[xx][yy] == 1)
                {
                    q.push({xx, yy});
                    grid[xx][yy] = 2;
                    area++;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, findArea(grid, m, n, i, j));
        return maxArea;
    }
};