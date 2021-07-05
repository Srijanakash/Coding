/*
 * Here, we will learn operations on queues.

Given N integers, the task is to insert those elements in the queue. Also, given M integers,
task is to find the frequency of each number in the Queue.

Example:

Input:
8
1 2 3 4 5 2 3 1
5
1 3 2 9 10

Output:
2
2
2
-1
-1

Explanation:
After inserting 1, 2, 3, 4, 5, 2, 3, 1 into the queue,
frequency of 1 is 2, 3 is 2, 2 is 2, 9 is -1 and 10 is
-1 (since, 9 and 10 is not there in the queue).
 */



// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
// Helper class Solution to implement
// insert() and findFrequency()
class Solution
{
    unordered_map<int, int>umap;
    public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k)
    {
        // Your code here
        q.push(k);
        umap[k]++;
    }

    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k)
    {
        // Your code here
        if(umap.find(k) != umap.end())
            return umap[k];
        return -1;
    }

};

// { Driver Code Starts.
int main() {

		int testcase;
		cin>>testcase;

		while(testcase-- > 0){
		    // Declaring Queue
		    queue<int> q;
		    int n, k;
		    cin>>n;

		    // Invoking object of Geeks class
		    Solution obj;

		    for(int i = 0;i<n;i++){
		        cin >> k;
		        obj.insert(q, k);
		    }

		    int m;
		    cin >> m;
		    for(int i = 0;i<m;i++){
		        cin >> k;
		        int f = obj.findFrequency(q, k);
		        if(f != 0){
		            cout<<f<<endl;
		        }
		        else{
		            cout<<"-1\n";
		        }
		    }
		}
	return 0;
}  // } Driver Code Ends
