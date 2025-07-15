package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Boj1976 {

    static int N;
    static int M;
    static Set<Integer>[] graph;

    public static boolean isConnected(int v1, int v2) {
        boolean[] visited = new boolean[N + 1];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(v1);
        while (!queue.isEmpty()) {
            int curV = queue.poll();
            if (curV == v2) return true;

            // 현재 정점과 연결된 모든 정점을 탐색
            for (int v : graph[curV]) {
                if (!visited[v]) {
                    visited[v] = true;
                    queue.add(v);
                }
            }
        }
        return false;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        graph = new Set[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new HashSet<>();
        }

        for (int v1 = 1; v1 <= N; v1++) {
            String[] input = br.readLine().split(" ");
            for (int v2 = 1; v2 <= N; v2++) {
                int isConnected = Integer.parseInt(input[v2 - 1]);
                if (isConnected == 1) {
                    graph[v1].add(v2);
                    graph[v2].add(v1);
                }
            }
        }

        String[] input = br.readLine().split(" ");
        for (int i = 1; i < M; i++) {
            int prev = Integer.parseInt(input[i - 1]);
            int cur = Integer.parseInt(input[i]);
            if (!isConnected(prev, cur)) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
