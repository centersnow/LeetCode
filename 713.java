import java.util.*;

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1)
            return 0;
        int res = 0, product = 1, index = 0;
        for (int i = 0; i < nums.length; i++) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[index];
                index++;
            }
            res += (i - index + 1);
        }
        return res;
    }
}
