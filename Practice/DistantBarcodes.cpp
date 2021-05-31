/*
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal.  
You may return any answer, and it is guaranteed an answer exists.

Example 1:

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]
*/

typedef pair<int,int>iPair;
class Solution 
{
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        unordered_map<int,int>umap;
        vector<int>res;
        int n=barcodes.size();
        if(n==0)
            return res;
        for(int i=0;i<n;i++)
            umap[barcodes[i]]++;
        priority_queue<iPair>pq;
        for(auto i=umap.begin();i!=umap.end();i++)
            pq.push(make_pair(i->second,i->first));
        iPair prev={-1,-1};
        while(!pq.empty())
        {
            iPair temp=pq.top();
            pq.pop();
            res.push_back(temp.second);
            if (prev.first > 0) 
                pq.push(prev); 
            temp.first--; 
            prev = temp; 
        }
        return res;
    }
};
