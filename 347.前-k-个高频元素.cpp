/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            record[nums[i]]++;
        }
        int n = record.size();
        // 小根堆
        priority_queue<pair<int, int>,
                       vector<pair<int, int> >,
                       greater<pair<int, int> > >
            pq;
        for (auto it = record.begin(); it != record.end(); it++)
        {
            if (k == pq.size())
            {
                if (it->second > pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            }
            else
            {
                pq.push(make_pair(it->second, it->first));
            }
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
