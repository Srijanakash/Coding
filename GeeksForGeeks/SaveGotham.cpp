/*
 * Gotham has been attacked by Joker . Bruce Wayne has deployed an automatic machine gun at each tower of Gotham.
All the towers in Gotham are in a straight line.
You are given no of towers 'n' followed by the height of 'n' towers.
For every tower(p), find the height of the closest tower (towards the right), greater than the height of the tower(p).
Now, the Print sum of all such heights (mod 1000000001).

Note: If for a tower(k), no such tower exists then take its height as 0.

Example 1:

Input : arr[]= {112, 133, 161, 311, 122,
                    512, 1212, 0, 19212}
Output : 41265
Explanation:
nextgreater(112) : 133
nextgreater(133) : 161
nextgreater(161) : 311
nextgreater(311) : 512
nextgreater(122) : 512
nextgreater(512) : 1212
nextgreater(1212) : 19212
nextgreater(0) : 19212
nextgreater(19212) : 0
add = 133+161+311+512+512+1212+19212+19212+0
add = 41265.

Example 2:

Input : arr[] = {5, 9, 7, 6}
Output :  9
 *
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {

    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout << save_gotham(arr, n) << endl;
    }

	return 0;
}// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    // Complete the function
    long long sum = 0, mod = 1000000001;
    stack<long long >st;
    st.push(0);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        sum += st.empty()? 0: st.top();
        st.push(arr[i]);
    }
    sum %= mod;
    return sum;
}
