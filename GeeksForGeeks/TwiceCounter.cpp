/*
 * Given a list of N words. Count the number of words that appear exactly twice in the list.

Example 1:

Input:
N = 3
list = {Geeks, For, Geeks}
Output: 1
Explanation: 'Geeks' is the only word that
appears twice.
Example 2:

Input:
N = 8
list = {Tom, Jerry, Thomas, Tom, Jerry,
Courage, Tom, Courage}
Output: 2
Explanation: 'Jerry' and 'Courage' are the
only words that appears twice.
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int countWords(string list[], int n)
        {
            //code here.
            unordered_map<string, int>umap;
            for(int i=0;i<n;i++)
                umap[list[i]]++;
            int count = 0;
            for(auto i = umap.begin(); i != umap.end(); i++)
                if(i->second == 2)
                    count++;
            return count;
        }

};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
