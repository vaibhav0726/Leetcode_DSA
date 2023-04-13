class Solution {
    public int maxDotProduct(int[] arr1, int[] arr2) {
        int dp[][] = new int[arr1.length + 1][arr2.length + 1];
        for(int[]a : dp){
            Arrays.fill(a, -1);
        }
        return Product(arr1, arr2, 0, 0, false, dp);
    }
    public static int Product(int[] arr1, int[] arr2, int i, int j, boolean flag, int dp[][]) {
        if (i == arr1.length || j == arr2.length) {
            if (flag) return 0;
            else return -10000000;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int dot = arr1[i] * arr2[j] + Product(arr1, arr2, i + 1, j + 1, false, dp);
        int fd = Product(arr1, arr2, i + 1, j, false, dp);
        int sd = Product(arr1, arr2, i, j + 1, false, dp);
        return dp[i][j] = Math.max(arr1[i] * arr2[j], Math.max(fd, Math.max(dot, sd)));
    }
}