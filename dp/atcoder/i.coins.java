import java.io.*;
import java.util.*;
import java.lang.Math.*;

class Main {
    static double[][] dp = new double[3001][3001];
    public static void main(String[] args) throws IOException {
        File inputFile = new File("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt");
        if (inputFile.exists()) {
            System.setIn(new FileInputStream("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt"));
            System.setOut(new PrintStream("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt"));
        }
        FastScanner sc = new FastScanner();
        int n = sc.nint();
        double[] p = sc.aint(); // probabilities of head
        
        // base cases: with 1 coin and get 1 or 0 head
        dp[1][1] = p[0]; 
        dp[1][0] = 1 - p[0];

        // fill the dp table
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                // dp[i][j] = probability of getting j heads with i coins
                dp[i][j] = dp[i - 1][j] * (double) (1 - p[i - 1]);
                if (j > 0) 
                    dp[i][j] += dp[i - 1][j - 1] * p[i - 1]; // head
            }
        }

        double ans = 0;
        for (int i = (n + 1) / 2; i <= n; i++) {
            ans += dp[n][i]; // sum probabilities of getting more than half heads
        }
        System.out.printf("%.10f\n", ans);
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

        double[] aint() {
            String s = readline();
            return Arrays.stream(s.split(" ")).mapToDouble(Double::parseDouble).toArray();
        }
    }
}