import java.util.*;

class Solution {
    public int findLength(int[] A, int[] B) {
        int res = 0;
        int[][] f = new int[A.length + 1][B.length + 1];
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    res = Math.max(res, f[i][j]);
                }
            }
        }
        return res;
    }
}
