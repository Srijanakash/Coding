/*
 * Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed
 * from digits of the array. All digits of given array must be used to form the two numbers.



Example 1:

Input:
N = 6
arr[] = {6, 8, 4, 5, 2, 3}
Output:
604
Explanation:
The minimum sum is formed by numbers
358 and 246


Example 2:

Input:
N = 5
arr[] = {5, 3, 0, 7, 4}
Output:
82
Explanation:
The minimum sum is formed by numbers
35 and 047
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long int
class Solution
{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        ll a=0, b=0;
        priority_queue<ll, vector<ll>, greater<ll>>pq;
        for(int i=0;i<n;i++)
            pq.push(arr[i]);
        bool flag=false;
        while(!pq.empty())
        {
            if(flag)
            {
                a = a*10+pq.top();
                pq.pop();
            }
            else
            {
                b = b*10+pq.top();
                pq.pop();
            }
            flag = !flag;
        }
        return a+b;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
