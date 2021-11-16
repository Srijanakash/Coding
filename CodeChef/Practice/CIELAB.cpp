#include <iostream>
using namespace std;

int main() 
{
	// your code goes here
	int a, b;
	cin>>a>>b;
	int res = a-b;
	if(res%10==9)
	    res--;
	else
	    res++;
	cout<<res;
	return 0;
}
