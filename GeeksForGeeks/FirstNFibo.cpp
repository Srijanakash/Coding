//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
vector<long long> printFibb(int);



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<long long> ans = printFibb(n);
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


//User function template for C++

// n : given integer value
// print the nth fibb number in the function 
vector<long long> printFibb(int n) 
{
    vector<long long>res;
    res.push_back(1);
    if(n==1)
        return res;
    res.push_back(1);
    if(n==2)
        return res;
    for(int i=2;i<n;i++)
        res.push_back(res[i-1]+res[i-2]);
    return res;
}
