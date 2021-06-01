/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for(auto i=umap.begin();i!=umap.end();i++)
        {
            pq.push(make_pair(i->second, i->first));
            if(pq.size() > k) 
                pq.pop();
        }
        vector<int>res;
        while(!pq.empty()) 
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
