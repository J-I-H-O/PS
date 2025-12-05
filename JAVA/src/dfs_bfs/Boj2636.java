package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj2636 {

    static int[][] cheese;
    static int h, w;
    static int[] dr = {1, -1, 0, 0};
    static int[] dc = {0, 0, 1, -1};

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        h = Integer.parseInt(input[0]);
        w = Integer.parseInt(input[1]);

        cheese = new int[h][w];
        int cheeseCnt = 0;
        for (int i = 0; i < h; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < w; j++) {
                cheese[i][j] = Integer.parseInt(input[j]);
                if (cheese[i][j] == 1) cheeseCnt++;
            }
        }

        int timeCnt = 0;
        int prevCheeseCnt = 0;
        while (cheeseCnt > 0) {
            timeCnt++;
            prevCheeseCnt = cheeseCnt;

            boolean[][] visited = new boolean[h][w];
            Queue<int[]> queue = new LinkedList<>();
            queue.add(new int[]{0, 0}); // 0, 0부터 탐색 시작
            visited[0][0] = true;
            while (!queue.isEmpty()) {
                int[] cur = queue.poll();
                for (int dir = 0; dir < 4; dir++) {
                    int nextR = cur[0] + dr[dir];
                    int nextC = cur[1] + dc[dir];

                    if (0 > nextR || nextR >= h || 0 > nextC || nextC >= w) continue;
                    if (visited[nextR][nextC]) continue;

                    if (cheese[nextR][nextC] == 0) {
                        queue.add(new int[]{nextR, nextC});
                        visited[nextR][nextC] = true;
                    } else {
                        cheeseCnt--;
                        cheese[nextR][nextC] = 0;
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }
        System.out.println(timeCnt);
        System.out.println(prevCheeseCnt);
    }
}
