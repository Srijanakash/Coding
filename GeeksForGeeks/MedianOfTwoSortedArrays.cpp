//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int findMedian(int *, int , int *, int);

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    
	    if(n < m)
	        cout << findMedian(arr, n, brr, m) << endl;
	   else
	        cout << findMedian(brr, m, arr, n) << endl;
	    
	}

}// } Driver Code Ends
//User function template for C++

// arr : given array with size n 
// brr : given array with size m
int kth(int arr1[], int m, int arr2[], int n, int k) 
{ 
    if (k > (m+n) || k < 1) 
        return -1; 
    if (m > n) 
        return kth(arr2, n, arr1, m, k); 
    if (m == 0) 
        return arr2[k - 1]; 
    if (k == 1) 
        return min(arr1[0], arr2[0]); 
    int i = min(m, k / 2), j = min(n, k / 2); 
    if (arr1[i - 1] > arr2[j - 1] )  
        return kth(arr1, m, arr2 + j, n - j, k - j); 
    else 
        return kth(arr1 + i, m - i, arr2, n, k - i); 
} 
int findMedian(int arr[], int n, int brr[], int m)
{
    int mid=m+n,res;
    if(mid%2==0)
        res=(kth(arr,n,brr,m,mid/2)+kth(arr,n,brr,m,mid/2+1))/2;
    else
        res=kth(arr,n,brr,m,mid/2+1);
    return res;
}
