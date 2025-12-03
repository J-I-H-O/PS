package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj9328_naive {
    /**
     * 열쇠를 획득하면 기존에 갈 수 없던 길을 갈 수 있게 됨
     * 빈 칸이거나, 현재 가지고 있는 열쇠에 대응되는 문인 경우 진행 가능
     * 출발은 일단 모서리에 있는 칸에서 시작, 각각의 칸에 대해 DFS/BFS 수행
     * 이때 진행할 수 있는 칸의 개수를 세는데, 이전에 진행했던 칸의 개수와 현재 진행한 칸의 개수가 같을 때 까지 반복
     */
    private static final int DIFF = 'a' - 'A';

    private static int t, h, w;
    private static char[][] map;
    private static int[] dr = {1, -1, 0, 0};
    private static int[] dc = {0, 0, 1, -1};
    private static int curDepth;
    private static String keys;
    private static int ans;

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            String[] input = br.readLine().split(" ");
            h = Integer.parseInt(input[0]);
            w = Integer.parseInt(input[1]);

            map = new char[h][w];
            for (int i = 0; i < h; i++) {
                map[i] = br.readLine().toCharArray();
            }
            keys = br.readLine();

            ans = 0;
            int prevDepth = -1; // 이전 시도에서 방문한 칸의 개수
            curDepth = 0;       // 현재 시도에서 방문한 칸의 개수
            while (prevDepth != curDepth) { // 이전 시도에서 방문한 칸의 개수와 현재 시도에서 방문한 칸의 개수가 같다는 것은 더이상 진행할 수 없다는 의미
                prevDepth = curDepth;
                curDepth = 0;

                // 모서리 칸만 입구가 될 수 있음
                for (int curR = 0; curR < h; curR++) {
                    boolean[][] visited = new boolean[h][w];
                    dfs(curR, 0, visited);
                }
                for (int curR = 0; curR < h; curR++) {
                    boolean[][] visited = new boolean[h][w];
                    dfs(curR, w - 1, visited);
                }
                for (int curC = 0; curC < w; curC++) {
                    boolean[][] visited = new boolean[h][w];
                    dfs(0, curC, visited);
                }
                for (int curC = 0; curC < w; curC++) {
                    boolean[][] visited = new boolean[h][w];
                    dfs(h - 1, curC, visited);
                }
            }
            System.out.println(ans);
        }
    }

    private static void dfs(int curR, int curC, boolean[][] visited) {
        if (curR < 0 || curR >= h || curC < 0 || curC >= w) return;
        if (map[curR][curC] == '*') return;
        if (visited[curR][curC]) return;
        if ('A' <= map[curR][curC] && map[curR][curC] <= 'Z' && !hasKey(map[curR][curC], keys)) return;

        curDepth++;
        visited[curR][curC] = true;

        if ('a' <= map[curR][curC] && map[curR][curC] <= 'z') {
            keys += map[curR][curC];
        }
        if (map[curR][curC] == '$') {
            ans++;
        }
        map[curR][curC] = '.';

        for (int dir = 0; dir < 4; dir++) {
            int nextR = curR + dr[dir];
            int nextC = curC + dc[dir];

            dfs(nextR, nextC, visited);
        }
    }

    private static boolean hasKey(char door, String keys) {
        char[] keyArr = keys.toCharArray();
        for (char key : keyArr) {
            if (key - door == DIFF) return true;
        }
        return false;
    }
}
