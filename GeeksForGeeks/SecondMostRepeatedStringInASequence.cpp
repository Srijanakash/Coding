/*
 * Given a sequence of strings, the task is to find out the second most repeated (or frequent)
 * string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most
occurring string with frequency 2.

​Example 2:

Input:
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int>umap;
        for(int i=0;i<n;i++)
            umap[arr[i]]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>pq;
        for(auto i=umap.begin();i!=umap.end();i++)
        {
            pq.push({i->second, i->first});
            if(pq.size() > 2)
                pq.pop();
        }
        return pq.top().second;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
