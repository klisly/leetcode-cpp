/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include <vector>
#include "time.h"
using namespace std;

// @lc code=start
class Solution
{
public:
    int partition(vector<int> &nums, int lidx, int ridx)
    {
        int pivot = nums[ridx];
        int i = lidx - 1;
        for (int j = lidx; j <= ridx - 1; j++)
        {
            if (nums[j] <= pivot)
            {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[ridx]);
        return i + 1;
    }
    int random_partition(vector<int> &nums, int lidx, int ridx)
    {
        int i = rand() % (ridx - lidx + 1) + lidx;
        swap(nums[ridx], nums[i]);
        return partition(nums, lidx, ridx);
    }
    void randomized_quicksort(vector<int> &nums, int lidx, int ridx)
    {
        // 随机选择切分节点
        if (lidx < ridx)
        {
            int pos = random_partition(nums, lidx, ridx);
            randomized_quicksort(nums, lidx, pos - 1);
            randomized_quicksort(nums, pos + 1, ridx);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
// @lc code=end
// [5,1,1,2,0,0]\n[0,0,1,1,2,5]
