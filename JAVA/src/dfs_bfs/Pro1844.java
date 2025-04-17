package dfs_bfs;

import java.util.LinkedList;
import java.util.Queue;

public class Pro1844 {
    public int solution(int[][] maps) {
        int[] dx = new int[]{1, 0, -1, 0};
        int[] dy = new int[]{0, 1, 0, -1};
        int n = maps.length;
        int m = maps[0].length;
        boolean[][] visited = new boolean[n][m];
        int ans = -1;

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0, 1});
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curX = cur[0];
            int curY = cur[1];
            int curCnt = cur[2];

            if (curX == n - 1 && curY == m - 1) {
                ans = curCnt;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m
                        && maps[nextX][nextY] != 0 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    queue.add(new int[]{nextX, nextY, curCnt + 1});
                }
            }
        }
        return ans;
    }
}
