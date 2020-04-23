/*
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].
Now we want to hire exactly K workers to form a paid group.  
When hiring a group of K workers, we must pay them according to the following rules:
Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately.
*/

class Solution 
{
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) 
    {
        vector <pair<double, pair<int, int>>> arr;
        for (int i = 0; i < quality.size(); i++)
            arr.push_back(make_pair((double)wage[i] / quality[i], make_pair(wage[i],
                                                                            quality[i])));
        sort(arr.begin(), arr.end());
        int sum = 0;
        priority_queue<int> q;
        for(int i=0; i<K-1; i++) 
        {
            sum += arr[i].second.second;
            q.push(arr[i].second.second);
        }
        double ans = (sum * arr[K-1].first) + arr[K-1].second.first;
        for(int i=K; i<arr.size(); i++) 
        {
            q.push(arr[i-1].second.second);
            sum += arr[i-1].second.second;
            sum -=q.top();
            q.pop();
            ans = min(ans, (sum * arr[i].first) + arr[i].second.first);
        }
        return ans;
    }
};
