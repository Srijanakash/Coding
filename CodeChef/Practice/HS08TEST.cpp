#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int x;
	float y;
	cin>>x>>y;
	if((x>0) && (x<=2000) && (y>=0) && (y<=2000))
	{
	    if(((x+0.50)<=y) && (x%5==0))
	    {
	        y=y-(x+0.50);
	        cout<<fixed<<setprecision(2)<<y<<endl;
	    }
	    else
	        cout<<fixed<<setprecision(2)<<y<<endl;
	}
	return 0;
}
