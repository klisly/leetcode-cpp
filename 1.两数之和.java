
/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */
import java.util.Map;
import java.util.TreeMap;

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = { -1, -1 };
        Map<Integer, Integer> num2idx = new TreeMap();
        for (int i = 0; i < nums.length; i++) {
            if (num2idx.containsKey(target - nums[i])) {
                res[0] = num2idx.get(target - nums[i]);
                res[1] = i;
            } else {
                num2idx.put(nums[i], i);
            }
        }
        return res;
    }
}
// @lc code=end
