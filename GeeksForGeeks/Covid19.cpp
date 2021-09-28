/*
 * Given the N*M binary matrix, 1 represents the healthy person, and 0 represents a patient affected by a coronavirus.
 * The task is to check the minimum time required for all persons to get affected.
 * A patient at [i, j] cell affects a person at cell [i, j-1], [i, j+1] [i+1, j] and [i-1, j] in one second.

Note: There will be at least one patient

Input:
1. The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
2. The first line of each test case contains two space-separated integers N and M.
3. Next N lines contain M space-separated binary integers.


Output: For each test case, print the minimum time required to all persons affected by COVID19


Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. 0 <= mat[i][j] <= 1


Example:
Input:
2
2 2
1 0
1 0
3 3
1 1 1
1 0 1
1 1 1

Output:
1
2

Explanation:
Test Case 2: After first second matrix will look like {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}.
After two seconds matrix will look like {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}.
 */



#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define ll long long int
#define mp make_pair
#define vi vector<int>
using namespace std;
int numberOfDays(vector<vector<int>> &grid, int r, int c)
{
    queue<pair<int, int>>q;
    int countDays = -1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(grid[i][j]==0)
                q.push({i,j});
    int row[] = {1, -1, 0, 0}, col[] = {0, 0, 1, -1};
    while(!q.empty())
    {
        int size = q.size();
        countDays ++;
        for(int j=0;j<size;j++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xx = x+row[i], yy = y+col[i];
                if(xx>=0 && yy>=0 && xx<r && yy<c && grid[xx][yy] == 1)
                {
                    grid[xx][yy] = 0;
                    q.push({xx, yy});
                }
            }
        }
    }
    return countDays;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    for(;t>0;t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>>graph;
        for(int i=0;i<r;i++)
        {
            vector<int>temp(c);
            for(int j=0;j<c;j++)
                cin>>temp[j];
            graph.push_back(temp);
        }
        cout<<numberOfDays(graph, r, c)<<"\n";
    }
	return 0;
}
