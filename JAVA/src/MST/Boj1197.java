package MST;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1197 {

    static List<Edge> edges = new ArrayList<>();
    static int[] parent;
    static int ans = 0;

    static class Edge {
        int from;
        int to;
        int weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    static boolean union(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        // 두 노드가 같은 루트 노드를 가지는 경우. 두 노드가 이미 같은 그래프에 속해있는 경우이므로, 간선 E(x, y)를 선택하면 사이클이 형성됨
        if (x == y) {
            return false;
        }
        parent[x] = y;
        return true;
    }

    // 노드 n의 루트 노드 찾기
    static int findParent(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = findParent(parent[n]);   // 상위 노드가 아닌, 현재 시점의 루트 노드를 가리키도록하여 다음번 동일한 호출 시 바로 루트 노드를 반환할 수 있도록 최적화
    }

    static void kruskal() {
        // 크루스칼 알고리즘 : 가중치가 낮은 간선부터 확인하며, 간선을 선택했을 때 사이클이 생성되지 않는다면 해당 간선을 선택
        edges.sort((edge1, edge2) -> edge1.weight - edge2.weight);
        for (Edge edge : edges) {
            if (union(edge.from, edge.to)) {
                ans += edge.weight;
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int V = Integer.parseInt(input[0]);
        int E = Integer.parseInt(input[1]);

        for (int i = 0; i < E; i++) {
            input = br.readLine().split(" ");
            int from = Integer.parseInt(input[0]);
            int to = Integer.parseInt(input[1]);
            int weight = Integer.parseInt(input[2]);
            edges.add(new Edge(from, to, weight));
        }

        parent = new int[V + 1];
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        kruskal();

        System.out.println(ans);
    }
}
