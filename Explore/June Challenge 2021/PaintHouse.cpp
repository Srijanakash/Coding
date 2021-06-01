/*
 * There is a row of n houses, where each house can be painted one of three colors: red, blue, or green.
 * The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.
 *
 * For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2]
 * is the cost of painting house 1 with color green, and so on...
 *
 * Return the minimum cost to paint all houses.
 *
 *
 *
 * Example 1:
 *
 * Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
 * Minimum cost: 2 + 5 + 3 = 10.
 *
 * Example 2:
 * Input: costs = [[7,6,2]]
 * Output: 2
 */


class Solution
{
public:
    int minCost(vector<vector<int>>& costs)
    {
        if(costs.size() == 0)
            return 0;
        vector<int> prevRow = costs[costs.size() - 1];
        for(int i = costs.size()-2; i >= 0; i--)
        {
            vector<int> currentRow;
            currentRow.assign(costs[i].begin(), costs[i].end());
            currentRow[0] += min(prevRow[1], prevRow[2]);
            currentRow[1] += min(prevRow[0], prevRow[2]);
            currentRow[2] += min(prevRow[1], prevRow[0]);
            prevRow = currentRow;
        }
        return *min_element(prevRow.begin(), prevRow.end());
    }
};