import java.io.*;
import java.util.*;
import java.lang.Math.*;

class Main {
    // dp[c1][c2][c3] = expected number of moves left to 
    // finish the game with c1, c2, c3 plates with 1, 2, 3 sushi respectively
    static double[][][] dp = new double[301][301][301];
    static int n;

    static double memo(int c1, int c2, int c3) {
        if (c1 < 0 || c2 < 0 || c3 < 0) 
            return 0;
        if (c1 == 0 && c2 == 0 && c3 == 0)
            return 0;
        if (dp[c1][c2][c3] > 0)
            return dp[c1][c2][c3];
        
        double res = n + c1 * memo(c1 - 1, c2, c3) 
                        + c2 * memo(c1 + 1, c2 - 1, c3) 
                        + c3 * memo(c1, c2 + 1, c3 - 1);
        return dp[c1][c2][c3] = res / (c1 + c2 + c3);
    }
    public static void main(String[] args) throws IOException {
        File inputFile = new File("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt");
        if (inputFile.exists()) {
            System.setIn(new FileInputStream("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt"));
            System.setOut(new PrintStream("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt"));
        }
        FastScanner sc = new FastScanner();

        n = sc.nint();
        int[] freq = new int[4];
        
        for (int i = 1; i <= n; i++) {
            int x = sc.nint();
            freq[x]++;
        }

        System.out.println(memo(freq[1], freq[2], freq[3]));
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