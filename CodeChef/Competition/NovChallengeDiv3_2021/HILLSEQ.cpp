#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define ll long long int
#define mp make_pair
#define vi vector<int>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(;t>0;t--)
    {
        int n;
        bool flag = true;
        map<ll, ll> m;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int val;
            cin>>val;
            m[val]++;
        }
        for(auto i = m.begin(); i != m.end(); i++)
        {
            auto j = m.rbegin();
            if(j->second == 2)
            {
                cout<<"-1\n";
                flag = false;
                break;
            }
            else if ( i->second > 2)
            {
                cout<<"-1\n";
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(auto i = m.begin(); i!= m.end(); i++)
                if(i->second == 2)
                    cout<< i->first <<" ";
            for(auto i = m.rbegin(); i != m.rend(); i++)
                cout<< i->first<<" ";
            cout<<endl;
        }
    }
    return 0;
}
