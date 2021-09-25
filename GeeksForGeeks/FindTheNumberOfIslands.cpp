/*
 * Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically or diagonally i.e., in all 8 directions.


Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0
There are two islands one is colored in blue
and other in orange.
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    void checkIslands(vector<vector<char>>& grid, int x, int y)
    {
        queue<pair<int, int>>q;
        q.push({x, y});
        grid[x][y]='2';
        int row[]={1,-1,0,0,1,1,-1,-1}, col[]={0,0,1,-1,1,-1,1,-1};
        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int xx = x+row[i], yy = y+col[i];
                if(xx<grid.size() && yy<grid[0].size() && x>=0 && yy>=0
                    && grid[xx][yy]=='1')
                    {
                        grid[xx][yy] = '2';
                        q.push({xx, yy});
                    }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid)
    {
        // Code here
        int countIslands = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    checkIslands(grid,i,j);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
