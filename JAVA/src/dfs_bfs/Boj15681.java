package dfs_bfs;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Boj15681 {

    /**
     * 1. 각 정점 간 연결 정보 저장 (그래프 형식)
     * 2. 루트 노드를 시작점으로, 현재 노드의 주변 노드에 대해 부모-자식 관계 판별(재귀). 이때 주변 노드가 현재 노드의 부모인 경우는 재귀를 건너뜀
     * 3. 루트 노드를 시작점으로, 현재 노드의 자식 노드를 루트로 하는 서브 트리의 크기를 재귀적으로 계싼
     */
    static int N, R, Q;
    static List<Integer>[] graph;       // 각 정점 간 연결 정보 저장
    static List<Integer>[] children;    // 각 정점의 자식 노드 저장
    static int[] parent;
    static int[] size;

    static void findChildren(int curNode, int parentNum) {
        for (int nearNode : graph[curNode]) {
            if (nearNode == parentNum) continue;
            children[curNode].add(nearNode);
            findChildren(nearNode, curNode);
        }
    }

    static int calcSubtreeSize(int curNode) {
        int subtreeSize = 1;
        for (int child : children[curNode]) {
            subtreeSize += calcSubtreeSize(child);
        }
        return size[curNode] = subtreeSize;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        R = Integer.parseInt(input[1]);
        Q = Integer.parseInt(input[2]);

        graph = new List[N + 1];
        children = new List[N + 1];
        parent = new int[N + 1];
        size = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
            children[i] = new ArrayList<>();
            parent[i] = i;
        }

        for (int i = 0; i < N - 1; i++) {
            input = br.readLine().split(" ");
            int v1 = Integer.parseInt(input[0]);
            int v2 = Integer.parseInt(input[1]);

            graph[v1].add(v2);
            graph[v2].add(v1);
        }

        findChildren(R, -1);
        calcSubtreeSize(R);

        for (int i = 0; i < Q; i++) {
            int root = Integer.parseInt(br.readLine());
            bw.write(size[root] + System.lineSeparator());
        }
        bw.flush();
    }
}
