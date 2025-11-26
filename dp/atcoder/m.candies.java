import java.io.*;
import java.util.*;
import java.lang.Math.*;

class Main {
    public static void main(String[] args) throws IOException {
        File inputFile = new File("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt");
        if (inputFile.exists()) {
            System.setIn(new FileInputStream("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt"));
            System.setOut(new PrintStream("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt"));
        }
        FastScanner sc = new FastScanner();

        int n = sc.nint(), k = sc.nint();
        int[] a = sc.aint();
        int mod = 1000000007;
        // find ways to distribute k candies to n kids such that each kid gets at most a[i] candies
        // dp[i][j] = number of ways to distribute j candies to first i kids
        long[][] dp = new long[n + 1][k + 1];
        long[] sum = new long[k + 5]; // prefix sum for dp[i][j]
        int currMax = a[0];

        for (int i = 0; i <= a[0]; i++) {
            dp[1][i] = 1; // 1 way for i candies for first kid
            sum[i + 1] = sum[i] + dp[1][i]; // prefix sum for first kid
        }

        for (int i = 2; i <= n; i++) {
            // j = candies distributed to first i kids
            for (int j = 0; j <= Math.min(k, currMax + a[i - 1]); j++) {
                dp[i][j] = (sum[Math.min(j + 1, currMax + 1)] - sum[Math.max(0, j - a[i - 1])] + mod) % mod;
            }
            currMax = Math.min(k, currMax + a[i - 1]);

            // reset & update prefix sum for current kid
            sum = new long[k + 5];
            for (int j = 0; j <= currMax; j++) {
                sum[j + 1] = (sum[j] + dp[i][j]) % mod; // prefix sum for current kid
            }
        }

        // for (int i = 0; i < sum.length; i++) {
        //     System.out.print(sum[i] + " ");
        // }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j <= k; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }

        System.out.println(dp[n][k] % mod);
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {}
            return st.nextToken();
        }

        int nint() { return Integer.parseInt(next()); }
        long lint() { return Long.parseLong(next());}
        double dint() { return Double.parseDouble(next()); }

        String readline() {
            String s = "";
            try {
                s = br.readLine().trim();
            } catch (IOException e) {}
            return s;
        }

        int[] aint() {
            String s = readline();
            return Arrays.stream(s.split(" ")).mapToInt(Integer::parseInt).toArray();
        }
    }
}