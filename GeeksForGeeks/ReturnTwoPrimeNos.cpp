#define ll long long int
#define pb push_back
#define MAX 10000
using namespace std;
bool sieve[MAX+1];
void primes()
{
    memset(sieve, true, sizeof(sieve)); 
    for (int p=2; p*p<=MAX; p++) 
    { 
        if (sieve[p] == true) 
        { 
            for (int i=p*p; i<=MAX; i += p) 
                sieve[i] = false; 
        } 
    } 
}
int main()
{
    primes();
    int t,n;
    cin>>t;
    for(;t>0;t--)
    {
        cin>>n;
        int start=2,end=0;
        for(;start<=n/2;start++)
        {
            end=n-start;
            if(sieve[start]==true && sieve[end]==true)
            {
                cout<<start<<" "<<end<<endl;
                break;
            }
        }
    }
	return 0;
}
