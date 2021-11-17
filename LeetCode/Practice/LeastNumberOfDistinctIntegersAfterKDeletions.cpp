/*
Given an array of integers arr and an integer k. 
Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
*/




class Solution 
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int, int>umap;
        for(int i=0;i<arr.size();i++)
            umap[arr[i]]++;
        vector<int> heap;
        for(auto x : umap)
            heap.push_back(x.second);
        sort(heap.begin(), heap.end());
        int n = heap.size();
        for(int i=0; i<n; i++){
            if(k < heap[i])
                return n-i;
            k -= heap[i];
        }
        return 0;
    }
};