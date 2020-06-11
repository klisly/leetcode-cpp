/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    
    int dp(vector<int> &gas, vector<int> &cost, int start, int cur, int res)
    {
        int curGas = gas[cur];
        int curCost = cost[cur];
        if (res + curGas >= curCost)
        {
            if (((cur + 1) % gas.size()) == start)
            {
                return start;
            }
            else
            {
                return dp(gas, cost, start,
                          (cur + 1) % gas.size(), res + curGas - curCost);
            }
        }
        else
        {

            return -1;
        }
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        for (int i = 0; i < gas.size(); i++)
        {
            int start = i, cur = i, res = 0;
            int idx = dp(gas, cost, start, cur, res);
            if (idx != -1)
            {
                return idx;
            }
        }
        return -1;
    }
};
// @lc code=end
