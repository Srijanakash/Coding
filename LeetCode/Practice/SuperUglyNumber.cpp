/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
*/

class Solution 
{
    struct Num 
    {
        int prime;
        int index;
        int next;
        Num(int p, int i, int n): prime(p), index(i), next(n) {}
    };
    struct myCompare 
    {
        bool operator()(Num a, Num b) 
        {
            return a.next > b.next;
        }
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        priority_queue<Num, vector<Num>, myCompare> pq;
        vector<int> ans = {1};
        for(int i : primes)
            pq.push(Num(i, 0, i));
        for(int i = 1; i < n; ++i) 
        {
            int tmp = pq.top().next;
            ans.push_back(tmp);
            while(pq.top().next == tmp) 
            {
                Num n = pq.top();
                pq.pop();
                pq.push(Num(n.prime, n.index + 1, n.prime * ans[n.index + 1]));
            }
        }
        return ans.back();
    }
};
