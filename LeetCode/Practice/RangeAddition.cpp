/*
You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, 
and you have some operation to apply on arr. In the ith operation, 
you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.

 

Example 1:


Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
Example 2:

Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]
*/




class Solution 
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        vector<int>res (length, 0);
        for(auto& tuples: updates)
        {
            int start = tuples[0], end = tuples[1], val = tuples[2];
            res[start] += val;
            if(end < length - 1)
                res[end + 1] -= val;
        }
        partial_sum(res.begin(), res.end(), res.begin());
        return res;
    }
};