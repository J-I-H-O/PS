package topologySort;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj1005 {

    /**
     * 1. 진입점이 될 수 있는(in-bound 간선이 없는) 노드 찾기
     * 2. (진입점 노드 ~ 목적지 노드)까지의 경로 최대 비용 구하기
     */
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int TC = 0; TC < T; TC++) {
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int K = Integer.parseInt(input[1]);

            input = br.readLine().split(" ");
            int[] costs = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                costs[i] = Integer.parseInt(input[i - 1]);
            }

            List<Integer>[] graph = new List[N + 1];
            for (int i = 1; i <= N; i++) {
                graph[i] = new ArrayList<>();
            }

            int[] inbound = new int[N + 1];
            for (int i = 0; i < K; i++) {
                input = br.readLine().split(" ");
                int v1 = Integer.parseInt(input[0]);
                int v2 = Integer.parseInt(input[1]);

                graph[v1].add(v2);
                inbound[v2]++;
            }

            int W = Integer.parseInt(br.readLine());

            // 진입점이 될 수 있는 정점 찾기
            Queue<Integer> queue = new LinkedList<>();    // {현재 정점 번호, 경로의 비용}
            int[] dp = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                if (inbound[i] == 0) {
                    queue.add(i);
                    dp[i] = costs[i];
                }
            }

            // 각 진입점으로부터 BFS
            while (!queue.isEmpty()) {
                int curV = queue.poll();
                if (curV == W) continue;

                for (int nextV : graph[curV]) {
                    // 다음 정점이 새로운 진입점이 될 수 있을 때에만 큐에 넣음 (중복되어 큐에 들어가는 현상 방지)
                    if (--inbound[nextV] == 0) {
                        queue.add(nextV);
                    }
                    // inbound 간선이 존재해 아직 진입점이 될 수 없는 경우에도 경로는 존재하므로 비용은 계산해줌
                    dp[nextV] = Math.max(dp[nextV], dp[curV] + costs[nextV]);
                }
            }
            bw.write(dp[W] + System.lineSeparator());
        }
        bw.flush();
        bw.close();
    }

}
