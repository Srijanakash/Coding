/*
 * Given a weighted, undirected and connected graph of V vertices and E edges.
 * The task is to find the sum of weights of the edges of the Minimum Spanning Tree.



Example 1:

Input:

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 */




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>visit(V,false);
        int ans=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int x=p.second;
            int w=p.first;
            if(visit[x])continue;
            visit[x]=true;
            ans+=w;
            for(auto y:adj[x]){
                if(!visit[y[0]]){
                    pq.push({y[1],y[0]});
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
