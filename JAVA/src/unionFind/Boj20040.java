package unionFind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj20040 {

    static int n, m;
    static int[] parent;

    // 사이클 형성 여부 반환
    static boolean union(int v1, int v2) {
        int p1 = find(v1);
        int p2 = find(v2);

        if (p1 == p2) {
            return true;
        } else if (p1 < p2) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
        }
        return false;
    }

    // 해당 정점이 속한 서브 그래프의 루트 노드 반환
    static int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int turn = 1; turn <= m; turn++) {
            input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            int v2 = Integer.parseInt(input[1]);

            if (union(v1, v2)) {
                System.out.println(turn);
                return;
            }
        }
        System.out.println(0);
    }
}
