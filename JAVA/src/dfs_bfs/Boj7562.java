package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj7562 {

    static int length;
    static boolean[][] visited;
    static int startX;
    static int startY;
    static int targetX;
    static int targetY;
    static int[] dx = {2, 2, -2, -2, 1, 1, -1, -1};
    static int[] dy = {1, -1, 1, -1, 2, -2, 2, -2};

    static int bfs() {
        Queue<int[]> queue = new LinkedList<>();    // x, y, cnt
        queue.add(new int[]{startX, startY, 0});
        visited[startX][startY] = true;

        while (!queue.isEmpty()) {
            int[] curPos = queue.remove();
            int curX = curPos[0];
            int curY = curPos[1];
            int curCnt = curPos[2];
            if (curX == targetX && curY == targetY) {
                return curCnt;
            }

            for (int i = 0; i < 8; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if (nextX < 0 || nextX >= length || nextY < 0 || nextY >= length || visited[nextX][nextY]) {
                    continue;
                }
                queue.add(new int[]{nextX, nextY, curCnt + 1});
                visited[nextX][nextY] = true;
            }
        }
        return -1;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (0 < T--) {
            length = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");
            startX = Integer.parseInt(input[0]);
            startY = Integer.parseInt(input[1]);
            input = br.readLine().split(" ");
            targetX = Integer.parseInt(input[0]);
            targetY = Integer.parseInt(input[1]);

            visited = new boolean[length][length];
            int ans = bfs();
            System.out.println(ans);
        }
    }
}
