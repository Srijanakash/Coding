#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll smallestDifference(vector<ll>&s, int n)
{
    sort(s.begin(), s.end());
    ll minDiff = INT_MAX;
    for(int i=1;i<n;i++)
    {
        ll temp = s[i] - s[i-1];
        minDiff = min(minDiff, temp);
    }
    return minDiff;
}
int main() 
{
	// your code goes here
	int t,n;
	cin>>t;
	for(;t>0;t--)
	{
	    cin>>n;
	    vector<ll>s(n);
	    for(int i=0;i<n;i++)
	        cin>>s[i];
	    cout<<smallestDifference(s, n)<<"\n";
	}
	return 0;
}
