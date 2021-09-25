/*
 * Aterp is the head nurse at a city hospital.
 * City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1]
(up, down, left and right) in unit time.
Help Aterp determine the minimum units of time after which there won't remain any uninfected patient
i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.




Example 1:

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1},
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st
unit time. And, during 2nd unit time, patient at
{1, 0} will get infected and will infect patient
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
Example 2:

Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.
 */




// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    bool checkAll(vector<vector<int>> hospital)
    {
        for(int i=0;i<hospital.size();i++)
        {
            for(int j=0;j<hospital[0].size();j++)
                if(hospital[i][j]==1)
                    return true;
        }
        return false;
    }
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        queue<pair<int, int>>q;
        int r=hospital.size(), c=hospital[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(hospital[i][j]==2)
                    q.push({i, j});
        int numberOfDays = -1;
        int row[] = {1, -1, 0, 0}, col[] = {0, 0, 1, -1};
        while(!q.empty())
        {
            int size = q.size();
            numberOfDays ++;
            for(int i=0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int xx = x+row[i];
                    int yy = y+col[i];
                    if(xx>=0 && yy>=0 && xx<r && yy<c
                        && hospital[xx][yy]==1)
                        {
                            hospital[xx][yy]=2;
                            q.push({xx, yy});
                        }
                }
            }
        }
        return checkAll(hospital)?-1:numberOfDays;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;

        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
