package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj2644 {

    static List<Integer>[] graph;
    static int[] parent;
    static int n, m;
    static int target1, target2;
    static int[] dist;

    static void dfs(int cur) {
        for (int next : graph[cur]) {
            if (dist[next] != 0) {
                continue;
            }
            dist[next] = dist[cur] + 1;
            dfs(next);
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        target1 = Integer.parseInt(input[0]);
        target2 = Integer.parseInt(input[1]);
        m = Integer.parseInt(br.readLine());

        graph = new List[n + 1];
        for (int i = 0; i < n + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            graph[x].add(y);
            graph[y].add(x);
        }

        dist = new int[n + 1];
        dist[target1] = 1;  // dist[i]가 0인 경우를 아직 방문하지 않은 경우로 정하기 위해 시작점 + 시작점과 형제 관계인 노드의 dist는 1로 초기화
        dfs(target1);

        if (dist[target2] == 0) {
            System.out.println(-1);
        } else {
            System.out.println(dist[target2] - 1);
        }
    }
}
