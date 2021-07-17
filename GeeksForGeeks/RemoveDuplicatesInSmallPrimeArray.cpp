/*
 * Given an array consisting of only prime numbers, remove all duplicate numbers from it.

Example 1:

Input:
N = 6
A[] = {2,2,3,3,7,5}
Output: 2 3 7 5
Explanation: After removing the duplicate
2 and 3 we get 2 3 7 5.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    vector<int> removeDuplicate(vector<int>& arr, int n)
    {
        // code here
        vector<int>res;
        unordered_set<int>uset;
        for(int i=0;i<n;i++)
            uset.insert(arr[i]);
        for(int i=0;i<n;i++)
        {
            if(uset.find(arr[i])!=uset.end())
            {
                uset.erase(arr[i]);
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        Solution obj;
        vector<int>result = obj.removeDuplicate(A,N);
        for(int i =0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;

    }
}
  // } Driver Code Ends
