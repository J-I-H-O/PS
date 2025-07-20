package topologySort;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj2623 {

    static int N;
    static int M;
    static List<Integer>[] graph;
    static int[] inDegree;  // 진입차수

    // 위상정렬
    public static List<Integer> topologySort() {
        List<Integer> result = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();

        // 진입차수가 0인 정점 삽입
        for (int curNode = 1; curNode <= N; curNode++) {
            if (inDegree[curNode] == 0) {
                queue.add(curNode);
            }
        }

        // 정점의 개수만큼 반복
        for (int i = 1; i <= N; i++) {
            // 아직 반복이 끝나지 않았는데 큐가 비어있는 것은 사이클이 존재한다는 의미로, 순서를 정할 수 없음
            if (queue.isEmpty()) break;

            // 큐에서 꺼낸 순서대로 정렬이 완료된 것
            int curNode = queue.poll();
            result.add(curNode);

            // 현재 노드 다음 순서의 진입차수를 하나씩 감소시키고, 진입차수가 0이 된 경우 큐에 삽입
            for (int nextNode : graph[curNode]) {
                if (--inDegree[nextNode] == 0) {
                    queue.add(nextNode);
                }
            }
        }
        return result;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        graph = new List[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        inDegree = new int[N + 1];
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            for (int cur = 1; cur < input.length - 1; cur++) {
                int curNode = Integer.parseInt(input[cur]);
                int nextNode = Integer.parseInt(input[cur + 1]);

                if (curNode == nextNode) continue;

                graph[curNode].add(nextNode);
                inDegree[nextNode]++;
            }
        }

        List<Integer> result = topologySort();

        if (result.size() < N) {
            System.out.println(0);
        } else {
            for (int node : result) {
                bw.write(node + "\n");
            }
        }
        bw.flush();
    }
}
