package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj17070 {

    static int N;
    static int[][] house;
    static int ans = 0;

    static void dfs(int dir, int r, int c) {
        if (r >= N || c >= N || house[r][c] == 1) {
            return;
        }
        if (dir == 2 && (house[r - 1][c] == 1 || house[r][c - 1] == 1)) {
            return;
        }

        if (r == N - 1 && c == N - 1) {
            ans++;
            return;
        }

        if (dir == 0) { // 가로 방향인 경우
            dfs(0, r, c + 1);
        } else if (dir == 1) { // 세로 방향인 경우
            dfs(1, r + 1, c);
        } else { // 대각 방향인 경우
            dfs(0, r, c + 1);
            dfs(1, r + 1, c);
        }
        dfs(2, r + 1, c + 1);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        house = new int[N][N];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                house[i][j] = Integer.parseInt(input[j]);
            }
        }

        // 한쪽 끝의 상태만 확인하면 됨
        dfs(0, 0, 1);
        System.out.println(ans);
    }
}
