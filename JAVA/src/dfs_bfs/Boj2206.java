package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj2206 {

    static int N;
    static int M;
    static int[][] map;
    static int[][][] dist;
    static int[] dx = new int[]{1, -1, 0, 0};
    static int[] dy = new int[]{0, 0, 1, -1};

    static int bfs() {
        Queue<int[]> queue = new LinkedList<>();    // {nx, ny, hasBroken}
        queue.add(new int[]{0, 0, 0});
        dist[0][0][0] = 1;

        while (!queue.isEmpty()) {
            int[] cur = queue.remove();
            int curX = cur[0];
            int curY = cur[1];
            int hasBroken = cur[2]; // 0: false, 1: true

            if (curX == N - 1 && curY == M - 1) {
                return dist[N - 1][M - 1][hasBroken];
            }

            for (int i = 0; i < 4; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
                    continue;
                }

                if (map[nextX][nextY] == 0) {
                    // 이전에 방문한 경우
                    if (dist[nextX][nextY][hasBroken] != 0) {
                        continue;
                    }
                    queue.add(new int[]{nextX, nextY, hasBroken});
                    dist[nextX][nextY][hasBroken] = dist[curX][curY][hasBroken] + 1;
                } else {
                    // 이전에 벽을 부순 적이 있거나, 더 빠른 시점에 해당 벽을 부수고 지나간 경우
                    if (hasBroken == 1 || dist[nextX][nextY][1] != 0) {
                        continue;
                    }
                    queue.add(new int[]{nextX, nextY, 1});
                    dist[nextX][nextY][1] = dist[curX][curY][0] + 1;
                }
            }
        }
        return -1;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        map = new int[N][M];
        dist = new int[N][M][2];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        int ans = bfs();
        System.out.println(ans);
    }
}
