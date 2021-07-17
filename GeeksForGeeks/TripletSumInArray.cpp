/*
 * Given an array arr of size n and an integer X.
 * Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in
the array sums up to 10.
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int v[], int n, int X)
    {
        //Your Code Here
        int count = 0;
        sort(v, v+n);
        for(int i=0;i<n-2;i++)
        {
            if (v[i] > X)
                break;
            int low = i+1, high = n-1;
            while(low < high)
            {
                int sum = v[i] + v[low] + v[high];
                if (sum == X)
                {
                    count++;
                    int last_left = v[low], last_right = v[high];
                    while (low < high && v[low] == last_left)
                        low++;
                    while (low < high && v[high] == last_right)
                        high--;
                }
                else if (sum < X)
                    low ++;
                else
                    high--;
            }
        }
        return count;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
