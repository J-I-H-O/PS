package shortestPath;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Boj1916_dijkstra_heap {

    static List<int[]>[] graph;
    static int[] dist;  // 출발 정점에서 i번째 정점까지의 최단거리 기록
    static int N, M;

    static void dijkstra(int start) {
        for (int i = 0; i <= N; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[start] = 0;

        // {노드 번호, 시작 노드에서 해당 노드까지의 비용}
        PriorityQueue<int[]> pq = new PriorityQueue<>((node1, node2) -> node1[1] - node2[1]);
        pq.add(new int[]{start, 0});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            // 현재 찾은 비용이 지금까지 찾은 비용보다 큰 경우는 건너뜀 (우선순위 큐를 사용하는 경우 방문 처리를 따로 하지 않기 때문에 필요한 코드)
            if (cur[1] > dist[cur[0]]) {
                continue;
            }

            for (int[] neighbor : graph[cur[0]]) {
                int nextCost = cur[1] + neighbor[1];    // 현재 노드까지의 비용 + 다음 노드로 가는 비용
                if (nextCost < dist[neighbor[0]]) {
                    pq.add(new int[]{neighbor[0], nextCost});
                    dist[neighbor[0]] = nextCost;
                }
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        dist = new int[N + 1];
        graph = new List[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            String[] input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            int v2 = Integer.parseInt(input[1]);
            int weight = Integer.parseInt(input[2]);

            graph[v1].add(new int[]{v2, weight});
        }

        String[] input = br.readLine().split(" ");
        int v1 = Integer.parseInt(input[0]);
        int v2 = Integer.parseInt(input[1]);

        dijkstra(v1);

        System.out.println(dist[v2]);
    }
}
