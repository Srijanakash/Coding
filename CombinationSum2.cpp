/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

class Solution 
{
    void findCombinations(vector<int>&candidates,vector<int>&elements,vector<vector<int>>&res,int target,int start)
    {
        if(!target)
        {
            res.push_back(elements);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(i>start && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            elements.push_back(candidates[i]);
            findCombinations(candidates,elements,res,target-candidates[i],i+1);
            elements.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>>res;
        vector<int>elements;
        sort(candidates.begin(),candidates.end());
        findCombinations(candidates,elements,res,target,0);
        return res;
    }
};
