/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        if (prices.size() <= 1)
        {
            return profit;
        }
        int cur_min = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > cur_min)
            {
                if (i == prices.size() - 1 || prices[i + 1] < prices[i])
                {
                    profit += (prices[i] - cur_min);
                    if (i < prices.size() - 1 && prices[i + 1] < prices[i])
                    {
                        cur_min = prices[i + 1];
                        i++;
                    }
                }
            }
            else
            {
                cur_min = prices[i];
            }
        }
        return profit;
    }
};
// @lc code=end
