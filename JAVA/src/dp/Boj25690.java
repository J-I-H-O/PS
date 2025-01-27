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
     * - dp[i][0]: 현재 노드를 흰색으로 칠했을 때, 서브트리를 칠하는 최소 비용. 즉, 현재 노드를 흰색으로 칠했을 때의 비용(흰색 비용)과 모든 자식 노드가 흰색 또는 검정으로 칠해졌을 때의 최소 비용 합을 더한 값
     * - dp[i][1]: 현재 노드를 검정색으로 칠했을 때, 서브트리를 칠하는 최소 비용. 즉, 현재 노드를 검정색으로 칠했을 때의 비용(검정색 비용)과 모든 자식 노드가 반드시 흰색으로 칠해졌을 때의 비용 합
     */
    static int n;
    static List<Integer>[] tree;
    static int[][] costs;
    static long[][] dp;

    static void dfs(int curNode) {
        // 리프 노드로부터 상향식으로 서브 트리를 최소로 칠하는 비용 구하기
        dp[curNode][0] = costs[curNode][0];
        dp[curNode][1] = costs[curNode][1];

        for (int child : tree[curNode]) {
            dfs(child);
            dp[curNode][0] += Math.min(dp[child][0], dp[child][1]); // 현재 노드를 흰색으로 칠하는 경우, 자식 노드는 흰색 또는 검정색으로 칠할 수 있음. 이때 자식 노드를 루트 노드로 갖는 서브 트리 중 비용이 낮은 것을 하위 서브 트리로 선택
            dp[curNode][1] += dp[child][0]; // 현재 노드를 검정색으로 칠하는 경우, 자식 노드는 흰색으로만 칠할 수 있음. 즉, 자식 노드를 루트 노드로 갖는 서브 트리 중 자식 노드가 흰색인 서브 트리를 선택
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
