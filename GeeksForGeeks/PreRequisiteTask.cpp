/*
 * There are a total of N tasks, labeled from 0 to N-1.
 * Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1,
 * which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Example 1:

Input:
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should
have finished task 1, and to do task 3 you
should have finished task 2. So it is possible.
Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.
 */




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack,
                        vector<int>adj[])
    {
        if(visited[v] == false)
        {
            visited[v] = true;
            recStack[v] = true;
            for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if ( !visited[*i] && isCyclicUtil(*i, visited, recStack, adj) )
                    return true;
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites)
	{
	    // Code here
	    vector<int>graph[N];
	    for(int i=0;i<prerequisites.size();i++)
	        graph[prerequisites[i].first].push_back(prerequisites[i].second);

	    vector<bool>vis(N, false), recStack(N, false);
	    for(int i = 0; i < N; i++)
            if (isCyclicUtil(i, vis, recStack, graph))
                return false;
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
