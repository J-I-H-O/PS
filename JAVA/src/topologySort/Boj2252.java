package topologySort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj2252 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        List<Integer>[] graph = new List[N + 1];
        for (int v = 1; v <= N; v++) {
            graph[v] = new ArrayList<>();
        }

        Queue<Integer> selectable = new LinkedList<>();
        int[] inbound = new int[N + 1];
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            int s1 = Integer.parseInt(input[0]);
            int s2 = Integer.parseInt(input[1]);

            graph[s1].add(s2);
            inbound[s2]++;
        }

        for (int v = 1; v <= N; v++) {
            if (inbound[v] == 0) selectable.add(v);
        }

        StringBuilder ans = new StringBuilder();
        while (!selectable.isEmpty()) {
            int cur = selectable.poll();
            for (int next : graph[cur]) {
                inbound[next]--;
                if (inbound[next] == 0) {
                    selectable.add(next);
                }
            }
            ans.append(cur).append(" ");
        }
        System.out.println(ans);
    }
}
