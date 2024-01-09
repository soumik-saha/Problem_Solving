class Solution {
    public int[][] imageSmoother(int[][] img) {
        int m = img.length;
        int n = img[0].length;

        int[][] res = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int avg = 0, c = 0;
                for (int x = Math.max(i - 1, 0); x < Math.min(i + 2, m); x++) {
                    for (int y = Math.max(j - 1, 0); y < Math.min(j + 2, n); y++) {
                        avg += img[x][y];
                        c++;
                    }
                }
                res[i][j] = avg / c;
            }
        }

        return res;
    }
}
