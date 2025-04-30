package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj2146 {

    public static void solution() throws IOException {
        /**
         * 1. 각 섬을 다른 번호로 마킹
         * 2. 육지에서 바다로 뻗어나가는 방향으로 BFS. 이때 육지로부터의 거리를 마킹함
         * 3. 2의 과정에서 다른 섬에 의해 마킹된 바다를 마주치는 경우, 현재 섬에 의해 마킹된 count + 이전 섬에 의해 마킹된 count를 구함
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] dx = new int[]{1, -1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};
        int[][] map = new int[N][N];
        int[][][] dist = new int[N][N][2];   // {현재 바다 칸에 마킹을 남긴 육지 번호, 가장 가까운 육지로부터 현재 바다 칸 까지의 거리}
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        Queue<int[]> seaQueue = new LinkedList<>(); // {x, y, continentNum, dist}

        // 각 섬을 다른 번호로 마킹. -1, -2, -3, ...
        int continentNum = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 현재 칸이 아직 방문하지 않은 육지칸이 아닌 경우는 건너 뜀
                if (map[i][j] != 1) {
                    continue;
                }

                Queue<int[]> continentQueue = new LinkedList<>();    // {x, y}
                continentQueue.add(new int[]{i, j});
                map[i][j] = continentNum;

                seaQueue.add(new int[]{i, j, continentNum, 0});
                dist[i][j][0] = continentNum;   // 현재 칸에 마킹을 남긴 육지 번호
                dist[i][j][1] = 0;              // 가장 가까운 육지로부터 현재 바다 칸 까지의 거리

                while (!continentQueue.isEmpty()) {
                    int[] cur = continentQueue.poll();
                    int curX = cur[0];
                    int curY = cur[1];
                    for (int k = 0; k < 4; k++) {
                        int nextX = curX + dx[k];
                        int nextY = curY + dy[k];
                        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || map[nextX][nextY] != 1) {
                            continue;
                        }
                        continentQueue.add(new int[]{nextX, nextY});
                        map[nextX][nextY] = continentNum;

                        // 바다 칸을 BFS로 탐색하기 위한 큐를 미리 채워둠
                        seaQueue.add(new int[]{nextX, nextY, continentNum, 0});
                        dist[nextX][nextY][0] = continentNum;   // 현재 칸에 마킹을 남긴 육지 번호
                        dist[nextX][nextY][1] = 0;              // 가장 가까운 육지로부터 현재 바다 칸 까지의 거리
                    }
                }
                continentNum--;
            }
        }

        int ans = Integer.MAX_VALUE;
        while (!seaQueue.isEmpty()) {
            int[] cur = seaQueue.poll();
            int curX = cur[0];
            int curY = cur[1];
            int curContinentNum = cur[2];
            int curDist = cur[3];
            for (int k = 0; k < 4; k++) {
                int nextX = curX + dx[k];
                int nextY = curY + dy[k];
                // 범위를 벗어나거나, 바다 칸이 아니거나, 현재 대륙에서 이미 방문한 땅인 경우는 건너뜀
                if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N
                        || map[nextX][nextY] != 0 || dist[nextX][nextY][0] == curContinentNum) {
                    continue;
                }

                // 이미 다른 육지에서 해당 바다 칸을 방문한 경우
                if (dist[nextX][nextY][0] != 0) {
                    ans = Math.min(ans, dist[curX][curY][1] + dist[nextX][nextY][1]);
                    continue;
                }

                // 아직 방문하지 않은 칸인 경우
                seaQueue.add(new int[]{nextX, nextY, curContinentNum, curDist + 1});
                dist[nextX][nextY][0] = curContinentNum;
                dist[nextX][nextY][1] = curDist + 1;
            }
        }
        System.out.println(ans);
    }
}
