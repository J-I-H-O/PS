package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj2638 {

    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};
    static int[][] cheese;
    static boolean[][] isExposed;
    static int N;
    static int M;

    public static void markAsExposedDfs(int row, int col) {
        isExposed[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nextR = row + dr[i];
            int nextC = col + dc[i];

            if (0 > nextR || nextR >= N || 0 > nextC || nextC >= M) continue;
            if (isExposed[nextR][nextC]) continue;
            if (cheese[nextR][nextC] == 1) continue;

            markAsExposedDfs(nextR, nextC);
        }
    }

    // 메모리 초과남
    public static void markAsExposedBfs(int row, int col) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row, col});
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            isExposed[cur[0]][cur[1]] = true;

            for (int i = 0; i < 4; i++) {
                int nextR = cur[0] + dr[i];
                int nextC = cur[1] + dc[i];

                if (0 > nextR || nextR >= N || 0 > nextC || nextC >= M) continue;
                if (isExposed[nextR][nextC]) continue;
                if (cheese[nextR][nextC] == 1) continue;

                queue.add(new int[]{nextR, nextC});
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        cheese = new int[N][M];
        isExposed = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                cheese[i][j] = Integer.parseInt(input[j]);
            }
        }

        // 1. BFS로 치즈 외부/내부 구분
        markAsExposedDfs(0, 0);

        int time = 0;
        while (true) {
            List<int[]> melted = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (cheese[i][j] == 0) continue;

                    int exposeCnt = 0;
                    if (isExposed[i - 1][j]) exposeCnt++;
                    if (isExposed[i + 1][j]) exposeCnt++;
                    if (isExposed[i][j - 1]) exposeCnt++;
                    if (isExposed[i][j + 1]) exposeCnt++;

                    if (exposeCnt >= 2) {
                        melted.add(new int[]{i, j});
                    }
                }
            }
            // 녹은 치즈가 존재하지 않는다면 반복 중단
            if (melted.isEmpty()) break;
            // 2. 치즈 녹음 처리
            for (int[] pos : melted) {
                cheese[pos[0]][pos[1]] = 0;
            }
            // 3. 녹은 부분에 대해 내부/외부 구분 처리
            for (int[] pos : melted) {
                markAsExposedDfs(pos[0], pos[1]);
            }
            time++;
        }
        System.out.println(time);
    }
}
