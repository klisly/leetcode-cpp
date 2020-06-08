/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
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
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(prices[i] - min_price, profit);
            min_price = min(min_price, prices[i]);
        }
        return profit;
    }
};
// @lc code=end
