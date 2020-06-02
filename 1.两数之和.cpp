/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "map"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        map<int, int> numMap;
        auto it = nums.begin();
        for (int i = 0; i < nums.size(); i++)
        {
            int ele = nums[i];
            if (numMap.find(target - ele) != numMap.end())
            {
                res.push_back(numMap.find(target - ele)->second);
                res.push_back(i);
                break;
            }
            numMap.insert(pair<int, int>(nums[i], i));
        }
        return res;
    }
};
// @lc code=end
