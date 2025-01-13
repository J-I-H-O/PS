package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1167 {

    static int n;
    static List<int[]>[] tree;   // index: v1, value: {v2, weight}
    static boolean[] visited;
    static int target = 0;
    static long ans = 0;

    static void dfs(int curNode, long sum) {
        if (ans < sum) {
            target = curNode;
            ans = sum;
        }

        visited[curNode] = true;
        for (int i = 0; i < tree[curNode].size(); i++) {
            int nextNode = tree[curNode].get(i)[0];
            int nextWeight = tree[curNode].get(i)[1];

            if (!visited[nextNode]) {
                dfs(nextNode, sum + nextWeight);
            }
        }
        visited[curNode] = false;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            for (int idx = 1; !input[idx].equals("-1"); idx += 2) {
                int v2 = Integer.parseInt(input[idx]);
                int weight = Integer.parseInt(input[idx + 1]);
                tree[v1].add(new int[]{v2, weight});
            }
        }

        /**
         * 1) 임의의 정점을 시작점으로 최장 거리를 구하도록 dfs를 수행한 결과, 마지막으로 방문한 노드가 전체 트리의 최장 거리를 구성하는 노드 중 하나가 됨
         * 2) (1)에서 마지막으로 방문한 노드를 시작점으로 다시 dfs 수행 시, 그 결과가 전체 트리의 최장 거리가 됨
         */
        visited = new boolean[n + 1];
        dfs(1, 0);
        dfs(target, 0);
        System.out.println(ans);
    }
}
