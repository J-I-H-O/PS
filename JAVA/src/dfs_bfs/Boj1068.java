package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1068 {

    static int N;
    static List<Integer>[] tree;
    static boolean[] visited;
    static int deleted;
    static int ans = 0;
    static int root;

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        tree = new List[N];
        for (int i = 0; i < N; i++) {
            tree[i] = new ArrayList<>();
        }

        String[] input = br.readLine().split(" ");
        for (int curNode = 0; curNode < N; curNode++) {
            int curParent = Integer.parseInt(input[curNode]);
            if (curParent == -1) {
                root = curNode;
                continue;
            }
            tree[curParent].add(curNode);
        }

        deleted = Integer.parseInt(br.readLine());
        visited = new boolean[N];

        if (deleted == root) {
            System.out.println(0);
        } else {
            visited[root] = true;
            dfs(root);
            System.out.println(ans);
        }
    }

    public static void dfs(int node) {
        List<Integer> children = tree[node];

        int childCnt = 0;
        for (int child : children) {
            if (child != deleted && !visited[child]) {
                childCnt++;
                visited[child] = true;
                dfs(child);
            }
        }

        if (childCnt == 0) {
            ans++;
        }
    }
}
