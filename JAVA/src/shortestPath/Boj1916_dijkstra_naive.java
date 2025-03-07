package shortestPath;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1916_dijkstra_naive {

    static List<int[]>[] graph;
    static boolean[] visited;
    static int[] dist;  // 출발 정점에서 i번째 정점까지의 최단거리 기록
    static int N, M;

    static void dijkstra(int start) {
        for (int i = 0; i <= N; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[start] = 0;

        // 정점의 수 만큼 반복
        for (int i = 1; i <= N; i++) {
            // 아직 방문하지 않은 노드 중 방문 경로의 가중치(dist[j])가 가장 낮은 것 선택
            int minCost = Integer.MAX_VALUE;
            int minNode = 0;
            for (int j = 1; j <= N; j++) {
                if (!visited[j] && dist[j] < minCost) {
                    minCost = dist[j];
                    minNode = j;
                }
            }

            // 선택한 노드 방문처리 후 인접한 노드로의 경로 비용 갱신
            visited[minNode] = true;
            for (int[] edge : graph[minNode]) {
                dist[edge[0]] = Math.min(dist[edge[0]], dist[minNode] + edge[1]);
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        visited = new boolean[N + 1];
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
