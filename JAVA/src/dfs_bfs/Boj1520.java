package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1520 {

    static int M, N;
    static int[][] board;
    static int[][] dp;  // dp[r][c]: (r, c)를 거쳐 (M-1, N-1)로 갈 수 있는 경로의 수
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};

    static int dfs(int r, int c) {
        if (r == M - 1 && c == N - 1) return 1;
        if (dp[r][c] != -1) return dp[r][c];

        dp[r][c] = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (0 > nr || nr >= M || 0 > nc || nc >= N) continue;
            if (board[r][c] <= board[nr][nc]) continue;

            dp[r][c] += dfs(nr, nc);
        }
        return dp[r][c];
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        M = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);

        board = new int[M][N];
        dp = new int[M][N];
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                dp[i][j] = -1;
            }
        }
        System.out.println(dfs(0, 0));
    }
}
