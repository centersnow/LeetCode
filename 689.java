import java.util.*;

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int len = nums.length - k + 1;

        int[] sums = new int[len];
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
            if (i >= k - 1) {
                sums[i - k + 1] = sum;
            }
        }

        int index = 0;
        int[] left = new int[len];
        for (int i = 0; i < len; i++) {
            if (sums[i] > sums[index]) {    // use > instead of >= for lexicographically smallest
                index = i;
            }
            left[i] = index;
        }

        index = len - 1;
        int[] right = new int[len];
        for (int i = len - 1; i >= 0; i--) {
            if (sums[i] >= sums[index]) {   // use >= instead of > for lexicographically smallest
                index = i;
            }
            right[i] = index;
        }

        int[] res = {0, k, k * 2};
        for (int m = k; m + k < len; m++) {
            int l = left[m - k];
            int r = right[m + k];
            if (sums[l] + sums[m] + sums[r] > sums[res[0]] + sums[res[1]] + sums[res[2]]) {
                res[0] = l;
                res[1] = m;
                res[2] = r;
            }
        }
        return res;
    }
}
