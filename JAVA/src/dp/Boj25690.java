package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj25690 {

    /**
     * @formatter:off
     * - cost[i][0] : white, cost[i][1] : black
     * - dp[i][0]: i번 노드를 white로 칠했을 때, i번 노드를 루트 노드로 갖는 서브 트리를 칠하는 최소 비용 dp[i][1]: i번 노드를
     * - black으로 칠했을 때, i번 노드를 루트 노드로 갖는 서브 트리를 칠하는 최소 비용
     */
    static int n;
    static List<Integer>[] tree;
    static int[][] costs;
    static long[][] dp;

    static void dfs(int curNode) {
        dp[curNode][0] = costs[curNode][0];
        dp[curNode][1] = costs[curNode][1];

        for (int child : tree[curNode]) {
            dfs(child);
            dp[curNode][0] += Math.min(dp[child][0], dp[child][1]);
            dp[curNode][1] += dp[child][0];
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        tree = new List[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            String[] input = br.readLine().split(" ");
            tree[Integer.parseInt(input[0])].add(Integer.parseInt(input[1]));
        }

        costs = new int[n][2];
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            costs[i][0] = Integer.parseInt(input[0]);
            costs[i][1] = Integer.parseInt(input[1]);
        }

        dp = new long[n][2];
        dfs(0);
        System.out.println(Math.min(dp[0][0], dp[0][1]));
    }
}
