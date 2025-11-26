import java.io.*;
import java.util.*;
import java.lang.Math.*;

class Main {
    static int[] dp = new int[100001];
    static List<List<Integer>> adj = new ArrayList<>();

    // Function to find the longest path in a Directed Acyclic Graph (DAG)
    // using Depth First Search (DFS) and memoization.
    // Since its a DAG, no need to check for cycles by using visited array.
    static int dfs(int u) {
        if (dp[u] != 0) 
            return dp[u];
        for (int v : adj.get(u)) {
            dp[v] = dfs(v);
            dp[u] = Math.max(dp[v] + 1, dp[u]);
        }
        return dp[u];
    }
    public static void main(String[] args) throws IOException {
        File inputFile = new File("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt");
        if (inputFile.exists()) {
            System.setIn(new FileInputStream("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt"));
            System.setOut(new PrintStream("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt"));
        }
        FastScanner sc = new FastScanner();
        int n = sc.nint(), m = sc.nint();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nint() - 1, v = sc.nint() - 1;
            adj.get(u).add(v);
        }

        for (int i = 0; i < n; i++) {
            dfs(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp[i]);
        }
        System.out.println(ans);
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