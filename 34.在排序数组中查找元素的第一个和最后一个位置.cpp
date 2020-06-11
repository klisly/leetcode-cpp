/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findUpper(vector<int> &nums, int low, int high, int target)
    {
        if (low > high)
        {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target && (mid == high || nums[mid + 1] > target))
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        return findUpper(nums, low, high, target);
    }

    int findLower(vector<int> &nums, int low, int high, int target)
    {
        if (low > high)
        {
            return -1;
        }
        int mid = low + (high - low) / 2;
        // 临界条件
        if (nums[mid] == target && (mid == low || nums[mid - 1] < target))
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        return findLower(nums, low, high, target);
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2, -1);
        int low = 0;
        int high = nums.size() - 1;
        int h = findUpper(nums, low, high, target);
        int l = findLower(nums, low, high, target);
        res[0] = l;
        res[1] = h;
        return res;
    }
};
// @lc code=end
