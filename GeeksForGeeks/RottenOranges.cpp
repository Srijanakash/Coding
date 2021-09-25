/*
 * Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges.
A rotten orange at index [i,j] can rot other fresh orange at indexes
[i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.


Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    bool checkAll(vector<vector<int>>& grid)
    {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==1)
                    return true;
        return false;

    }
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid)
    {
        // Code here
        queue<pair<int, int>>q;
        int countDays = -1;
        int r = grid.size(), c = grid[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        int row[] = {1, -1, 0, 0}, col[] = {0, 0, 1, -1};
        while(!q.empty())
        {
            int size = q.size();
            countDays ++;
            for(int i=0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int xx = x+row[i], yy = y+col[i];
                    if(xx>=0 && yy>=0 && xx<r && yy<c && grid[xx][yy] == 1)
                    {
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
        }
        return !checkAll(grid)?countDays:-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
