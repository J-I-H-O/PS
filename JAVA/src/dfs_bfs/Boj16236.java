package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Boj16236 {

    public static void solution() throws IOException {
        int[] dr = {-1, 0, 0, 1};
        int[] dc = {0, -1, 1, 0};
        int initialR = -1;
        int initialC = -1;
        int time = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[N][N];

        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                if (board[i][j] == 9) {
                    initialR = i;
                    initialC = j;
                    board[i][j] = 0;
                }
            }
        }

        int sharkSize = 2;
        int eatCnt = 0;
        while (true) {
            List<int[]> encounterInfo = new ArrayList<>(); // {r, c, distance}
            int minDistance = Integer.MAX_VALUE;

            Queue<int[]> queue = new LinkedList<>(); // {r, c, distance}
            boolean[][] visited = new boolean[N][N];

            // 물고기를 먹거나, 더이상 이동할 수 없을 때 까지 반복
            queue.add(new int[]{initialR, initialC, 0});
            visited[initialR][initialC] = true;
            while (!queue.isEmpty()) {
                int[] cur = queue.poll();
                int curR = cur[0];
                int curC = cur[1];
                int curDistance = cur[2];

                // 지금까지 발견된 먹을 수 있는 물고기 까지의 최단 거리보다 더 먼 거리는 고려하지 않음
                if (curDistance > minDistance) break;

                // 현재 칸에 물고기가 있고, 먹을 수 있는 크기인 경우
                if (board[curR][curC] != 0 && sharkSize > board[curR][curC]) {
                    minDistance = curDistance;
                    encounterInfo.add(new int[]{curR, curC, curDistance});
                }

                for (int i = 0; i < 4; i++) {
                    int nextR = curR + dr[i];
                    int nextC = curC + dc[i];
                    int nextaDistance = curDistance + 1;

                    if (0 > nextR || nextR >= N || 0 > nextC || nextC >= N) continue;
                    if (visited[nextR][nextC]) continue;
                    if (sharkSize < board[nextR][nextC]) continue;

                    queue.add(new int[]{nextR, nextC, nextaDistance});
                    visited[nextR][nextC] = true;
                }
            }
            if (!encounterInfo.isEmpty()) {
                encounterInfo.sort((info1, info2) -> {
                    if (info1[0] == info2[0]) return info1[1] - info2[1];
                    return info1[0] - info2[0];
                });

                int[] cur = encounterInfo.get(0);
                int curR = cur[0];
                int curC = cur[1];
                int curDistance = cur[2];

                board[curR][curC] = 0;
                initialR = curR;
                initialC = curC;

                eatCnt++;
                if (eatCnt == sharkSize) {
                    sharkSize++;
                    eatCnt = 0;
                }
                time += curDistance;
            } else break;   // 현재 먹을 수 있는 물고기가 없는 경우 엄마 상어 호출
        }
        System.out.println(time);
    }
}
