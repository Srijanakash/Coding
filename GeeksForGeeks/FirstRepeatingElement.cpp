/*
 * Given an array arr[] of size n, find the first repeating element.
 * The element should occurs more than once and the index of its first occurrence should be the smallest.



Example 1:

Input:
n = 7
arr[] = {1, 5, 3, 4, 3, 5, 6}
Output: 2
Explanation:
5 is appearing twice and
its first appearence is at index 2
which is less than 3 whose first
occuring index is 3.

Example 2:

Input:
n = 4
arr[] = {1, 2, 3, 4}
Output: -1
Explanation:
All elements appear only once so
answer is -1.
 */



// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        //code here
        unordered_map<int, int>umap;
        for(int i=0;i<n;i++)
            umap[arr[i]]++;
        unordered_set<int>uset;
        for(auto i=umap.begin(); i!=umap.end(); i++)
            if(i->second >= 2)
                uset.insert(i->first);
        for(int i=0;i<n;i++)
            if(uset.find(arr[i])!=uset.end())
                return i+1;
        return -1;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int arr[n];

        for(int i = 0 ; i < n ; ++ i )
            cin >> arr[i] ;
        Solution ob;
        cout << ob.firstRepeated(arr,n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
