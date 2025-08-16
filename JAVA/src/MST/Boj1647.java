package MST;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Boj1647 {

    static int[] parent;

    static class Edge {
        int s, e, w;

        public Edge(int s, int e, int w) {
            this.s = s;
            this.e = e;
            this.w = w;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        // 가중치가 낮은 간선 먼저 선택하기 위해 PriorityQueue 사용
        PriorityQueue<Edge> pq = new PriorityQueue<>((e1, e2) -> e1.w - e2.w);
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            int s = Integer.parseInt(input[0]);
            int e = Integer.parseInt(input[1]);
            int w = Integer.parseInt(input[2]);
            pq.add(new Edge(s, e, w));
        }

        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        // N-1개의 간선을 선택해 MST 구성
        int weightSum = 0;
        int maxWeight = 0;
        int selectedCnt = 0;
        while (!pq.isEmpty() && selectedCnt < N - 1) {
            // 간선으로 연결된 두 정점이 서로 다른 부모를 가지는 경우(사이클을 형성하지 않는 경우), 현재 간선 선택
            Edge edge = pq.poll();
            if (find(edge.s) != find(edge.e)) {
                union(edge.s, edge.e);
                weightSum += edge.w;
                maxWeight = Math.max(maxWeight, edge.w);
                selectedCnt++;
            }
        }
        // MST를 구성하는 N-1개의 간선 중, 가중치가 가장 큰 것을 제거
        System.out.println(weightSum - maxWeight);
    }

    private static int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    private static void union(int v1, int v2) {
        int p1 = find(v1);
        int p2 = find(v2);
        parent[p1] = p2;
    }
}
