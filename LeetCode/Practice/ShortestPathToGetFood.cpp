/*
 * You are starving and you want to eat food as quickly as possible.
 * You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

'*' is your location. There is exactly one '*' cell.
'#' is a food cell. There may be multiple food cells.
'O' is free space, and you can travel through these cells.
'X' is an obstacle, and you cannot travel through these cells.
You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell.
If there is no path for you to reach food, return -1.



Example 1:


Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
Output: 3
Explanation: It takes 3 steps to reach the food.
Example 2:


Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
Output: -1
Explanation: It is not possible to reach the food.
Example 3:


Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
Output: 6
Explanation: There can be multiple food cells. It only takes 6 steps to reach the bottom food.
Example 4:

Input: grid = [["O","*"],["#","O"]]
Output: 2
Example 5:

Input: grid = [["X","*"],["#","X"]]
Output: -1
 */





class Solution
{
    int findTime(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = 'V';
        queue<pair<int, int>>q;
        q.push({x, y});
        int row[] = {1, -1, 0, 0}, col[] = {0, 0, 1, -1};
        int timeTaken = 0;
        while(!q.empty())
        {
            int size = q.size();
            timeTaken ++;
            for(int i=0;i<size;i++)
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int xx = x+row[i], yy = y+col[i];
                    if(xx>=0 && yy>=0 && xx<grid.size() && yy<grid[0].size())
                    {
                        if(grid[xx][yy] == '#')
                            return timeTaken;
                        if(grid[xx][yy] == 'O')
                        {
                            q.push({xx, yy});
                            grid[xx][yy] = 'V';
                        }
                    }
                }
            }
        }
        return -1;
    }
public:
    int getFood(vector<vector<char>>& grid)
    {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == '*')
                    return findTime(grid, i, j);
        return -1;
    }
};
