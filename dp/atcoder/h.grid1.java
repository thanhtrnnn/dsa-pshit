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

        int mod = 1000000007;
        int n = sc.nint(), m = sc.nint();
        char[][] a = new char[n + 1][m + 1];
        int [][] dp = new int[n + 1][m + 1]; // dp[i][j] = number of ways (1, 1) to cell (i, j)
        for (int i = 1; i <= n; i++) {
            a[i] = (" " + sc.readline()).toCharArray();
        }

        // initialize dp
        dp[1][1] = (a[1][1] == '#') ? 0 : 1; // start at (1, 1) if it's not a wall
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == '.') { // if it's an empty cell
                    if (i > 1) 
                        dp[i][j] += dp[i - 1][j]; // from above
                    if (j > 1) 
                        dp[i][j] += dp[i][j - 1]; // from left
                    dp[i][j] %= mod;
                }
            }
        }

        System.out.println(dp[n][m]); // print the number of ways to reach (n, m)

        // TESTING: print the grid
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }
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