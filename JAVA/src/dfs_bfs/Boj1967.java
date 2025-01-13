package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1967 {

    static int n;
    static List<int[]>[] tree;   // index: v1, value: {v2, weight}
    static List<Integer> leafs;
    static boolean[] visited;
    static int ans = 0;

    static void dfs(int curNode, int sum) {
        visited[curNode] = true;
        for (int i = 0; i < tree[curNode].size(); i++) {
            int nextNode = tree[curNode].get(i)[0];
            int nextWeight = tree[curNode].get(i)[1];

            if (!visited[nextNode]) {
                dfs(nextNode, sum + nextWeight);
            }
        }
        visited[curNode] = false;
        ans = Math.max(ans, sum);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        tree = new ArrayList[n + 1];
        leafs = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
            leafs.add(i);
        }

        for (int i = 0; i < n - 1; i++) {
            String[] input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            int v2 = Integer.parseInt(input[1]);
            int weight = Integer.parseInt(input[2]);

            // 부모 노드로 입력된 노드는 리프 노드가 아님
            if (leafs.contains(v1)) {
                leafs.remove(leafs.indexOf(v1));
            }

            tree[v1].add(new int[]{v2, weight});
            tree[v2].add(new int[]{v1, weight});
        }

        /**
         * 목표: 두 리프노드 사이의 거리가 가장 긴 것 찾기
         * 모든 리프노드를 시작점으로, 다른 리프노드에 도달할 때 까지 dfs
         */
        visited = new boolean[n + 1];
        for (int i = 0; i < leafs.size(); i++) {
            dfs(leafs.get(i), 0);
        }
        System.out.println(ans);
    }
}
