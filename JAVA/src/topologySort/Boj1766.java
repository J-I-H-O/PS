package topologySort;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Boj1766 {

    /**
     * 위상정렬
     * 매 반복마다 정점으로 들어오는 간선이 0개인 것을 선택.
     * 들어오는 간선이 0개인 정점이 여러개인 경우, 정점의 값이 가장 작은 것을 선택
     */
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        List<Integer>[] graph = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        int[] inboundEdge = new int[N + 1];
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            int v2 = Integer.parseInt(input[1]);

            graph[v1].add(v2);
            inboundEdge[v2]++;
        }

        // 정점의 값이 작은 순으로 출력하기 위해 최소 힙 사용
        // inboundEdge가 0인 정점을 PriorityQueue에 넣음
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int node = 1; node <= N; node++) {
            if (inboundEdge[node] == 0) pq.add(node);
        }

        while (!pq.isEmpty()) {
            int node = pq.poll();
            for (int next : graph[node]) {
                inboundEdge[next]--;
                if (inboundEdge[next] == 0) pq.add(next);
            }
            bw.write(node + " ");
        }
        bw.flush();
        bw.close();
    }
}
