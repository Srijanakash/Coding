/*
 * Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).


Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in
orange.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int findArea(vector<vector<int>>& grid, int x, int y)
    {
        queue<pair<int, int>>q;
        q.push({x, y});
        grid[x][y] = 2;
        int area = 1;
        int col[] = {1,1,0,-1,-1,-1,0,1}, row[] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int xx = x+row[i], yy = y+col[i];
                if(xx<grid.size() && yy<grid[0].size() && xx>=0 && yy>=0
                    && grid[xx][yy] == 1)
                    {
                        grid[xx][yy] = 2;
                        area++;
                        q.push({xx, yy});
                    }
            }
        }
        return area;
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid)
    {
        // Code here
        int maxArea = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, findArea(grid, i, j));
            }
        }
        return maxArea;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
