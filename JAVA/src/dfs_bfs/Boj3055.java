package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj3055 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int R = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);

        Queue<int[]> hedgehog = new LinkedList<>();  // <row, col, moveCnt>
        Queue<int[]> water = new LinkedList<>();
        int ans = -1;

        char[][] map = new char[R][C];
        boolean[][] visited = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            map[i] = br.readLine().toCharArray();
            for (int j = 0; j < C; j++) {
                if (map[i][j] == 'S') {
                    hedgehog.add(new int[]{i, j, 0});
                    visited[i][j] = true;
                }
                if (map[i][j] == '*') {
                    water.add(new int[]{i, j, 0});
                }
            }
        }

        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};

        for (int time = -1; !hedgehog.isEmpty(); time++) {
            // 물을 먼저 이동
            while (!water.isEmpty() && water.peek()[2] == time + 1) {
                int[] curWater = water.poll();
                for (int dir = 0; dir < 4; dir++) {
                    int nextWaterR = curWater[0] + dr[dir];
                    int nextWaterC = curWater[1] + dc[dir];

                    if (nextWaterR < 0 || nextWaterR >= R || nextWaterC < 0 || nextWaterC >= C) continue;
                    if (map[nextWaterR][nextWaterC] != '.') continue;

                    map[nextWaterR][nextWaterC] = '*';
                    water.add(new int[]{nextWaterR, nextWaterC, curWater[2] + 1});
                }
            }

            // 고슴도치 이동
            while (!hedgehog.isEmpty() && hedgehog.peek()[2] == time + 1) {
                int[] curHog = hedgehog.poll();
                for (int dir = 0; dir < 4; dir++) {
                    int nextHogR = curHog[0] + dr[dir];
                    int nextHogC = curHog[1] + dc[dir];

                    if (nextHogR < 0 || nextHogR >= R || nextHogC < 0 || nextHogC >= C) continue;
                    if (map[nextHogR][nextHogC] == '*' || map[nextHogR][nextHogC] == 'X') continue;
                    if (visited[nextHogR][nextHogC]) continue;

                    if (map[nextHogR][nextHogC] == 'D') ans = curHog[2] + 1;

                    hedgehog.add(new int[]{nextHogR, nextHogC, curHog[2] + 1});
                    visited[nextHogR][nextHogC] = true;
                }
            }
        }
        if (ans == -1) {
            System.out.println("KAKTUS");
            return;
        }
        System.out.println(ans);
    }
}
