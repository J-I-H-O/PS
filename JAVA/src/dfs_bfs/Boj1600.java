package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj1600 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int K = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int W = Integer.parseInt(input[0]);
        int H = Integer.parseInt(input[1]);

        boolean[][][] visited = new boolean[H][W][K + 1];
        int[][] board = new int[H][W];
        for (int i = 0; i < H; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < W; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};
        int[] hdr = {2, 2, -2, -2, 1, 1, -1, -1};
        int[] hdc = {1, -1, 1, -1, 2, -2, 2, -2};

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0, 0, 0});
        visited[0][0][0] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curR = cur[0];
            int curC = cur[1];
            int moveCnt = cur[2];
            int hMoveCnt = cur[3];

            if (curR == H - 1 && curC == W - 1) {
                System.out.println(moveCnt);
                return;
            }

            // 말 처럼 이동
            if (hMoveCnt < K) {
                for (int dir = 0; dir < 8; dir++) {
                    int nextR = curR + hdr[dir];
                    int nextC = curC + hdc[dir];

                    if (0 > nextR || nextR >= H || 0 > nextC || nextC >= W) continue;
                    if (board[nextR][nextC] == 1) continue;
                    if (visited[nextR][nextC][hMoveCnt + 1]) continue;

                    queue.add(new int[]{nextR, nextC, moveCnt + 1, hMoveCnt + 1});
                    visited[nextR][nextC][hMoveCnt + 1] = true;
                }
            }

            // 인접한 칸으로 이동
            for (int dir = 0; dir < 4; dir++) {
                int nextR = curR + dr[dir];
                int nextC = curC + dc[dir];

                if (0 > nextR || nextR >= H || 0 > nextC || nextC >= W) continue;
                if (board[nextR][nextC] == 1) continue;
                if (visited[nextR][nextC][hMoveCnt]) continue;

                queue.add(new int[]{nextR, nextC, moveCnt + 1, hMoveCnt});
                visited[nextR][nextC][hMoveCnt] = true;
            }
        }
        System.out.println(-1);
    }
}
