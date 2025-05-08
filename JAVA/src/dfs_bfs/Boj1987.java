package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1987 {

    static int R, C;
    static char[][] board;
    static int ans = 0;
    static boolean[] visited = new boolean[26];
    static int[] dr = new int[]{1, -1, 0, 0};
    static int[] dc = new int[]{0, 0, 1, -1};

    static void dfs(int curR, int curC, int depth) {
        ans = Math.max(ans, depth);

        for (int i = 0; i < 4; i++) {
            int nextR = curR + dr[i];
            int nextC = curC + dc[i];
            if (0 > nextR || nextR >= R || 0 > nextC || nextC >= C || visited[board[nextR][nextC] - 'A']) {
                continue;
            }

            visited[board[nextR][nextC] - 'A'] = true;
            dfs(nextR, nextC, depth + 1);
            visited[board[nextR][nextC] - 'A'] = false;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        R = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);

        board = new char[R][C];
        for (int i = 0; i < R; i++) {
            board[i] = br.readLine().toCharArray();
        }

        visited[board[0][0] - 'A'] = true;
        dfs(0, 0, 1);
        System.out.println(ans);
    }
}
