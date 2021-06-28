/*
 * Given an array, find maximum sum of smallest and second smallest elements chosen from all possible sub-arrays. More formally, if we write all (nC2) sub-arrays of array of size >=2 and find the sum of smallest and second smallest, then our answer will be maximum sum among them.


Example 1:

Input : arr[] = [4, 3, 1, 5, 6]
Output : 11
Subarrays with smallest and
second smallest are,
[4, 3]
smallest = 3    second smallest = 4
[4, 3, 1]
smallest = 1    second smallest = 3
[4, 3, 1, 5]
smallest = 1    second smallest = 3
[4, 3, 1, 5, 6]
smallest = 1    second smallest = 3
[3, 1]
smallest = 1    second smallest = 3
[3, 1, 5]
smallest = 1    second smallest = 3
[3, 1, 5, 6]
smallest = 1    second smallest = 3
[1, 5]
smallest = 1    second smallest = 5
[1, 5, 6]
smallest = 1    second smallest = 5
[5, 6]
smallest = 5    second smallest = 6
Maximum sum among all
above choices is, 5 + 6 = 11

Example 2:
Input : arr[] = {5, 4, 3, 1, 6}
Output : 9


Your Task:
You don't need to read input or print anything.
Your task is to complete the function pairWithMaxSum() which takes the array Arr[]
 and its size N as inputs and returns the maximum sum of smallest and second smallest elements chosen
 from all possible subarrays.
 */




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution
{
    public:
        long long pairWithMaxSum(long long arr[], long long n)
        {
            // Your code goes here
            long long windowSum = 0, maxSum = INT_MIN;
            windowSum = arr[0] + arr[1];
            maxSum = windowSum;
            for(int i=2; i<n; i++)
            {
                windowSum -= arr[i - 2];
                windowSum += arr[i];
                maxSum = max(maxSum, windowSum);
            }
            return maxSum;
        }
};



// { Driver Code Starts.
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}

  // } Driver Code Ends
