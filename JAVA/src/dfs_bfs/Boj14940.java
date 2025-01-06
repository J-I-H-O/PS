package dfs_bfs;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Boj14940 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);

        // init
        int targetRow = 0;
        int targetCol = 0;
        int[][] map = new int[n][m];
        int[][] dist = new int[n][m];
        for (int i = 0; i < n; i++) {
            inputs = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(inputs[j]);
                if (map[i][j] == 0) {
                    dist[i][j] = 0;
                } else if (map[i][j] == 1) {
                    dist[i][j] = -1;
                } else {
                    dist[i][j] = 0;
                    targetRow = i;
                    targetCol = j;
                }
            }
        }

        // bfs
        int[] dr = new int[]{0, 1, 0, -1};
        int[] dc = new int[]{1, 0, -1, 0};
        Queue<int[]> queue = new LinkedList<>();

        queue.add(new int[]{targetRow, targetCol});
        while (!queue.isEmpty()) {
            int[] curPosition = queue.remove();
            for (int i = 0; i < 4; i++) {
                int nextRow = curPosition[0] + dr[i];
                int nextCol = curPosition[1] + dc[i];

                if (0 <= nextRow && nextRow < n && 0 <= nextCol && nextCol < m && dist[nextRow][nextCol] == -1) {
                    queue.add(new int[]{nextRow, nextCol});
                    dist[nextRow][nextCol] = dist[curPosition[0]][curPosition[1]] + 1;
                }
            }
        }

        // 결과 출력
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(dist[i][j]).append(" ");
            }
            sb.append(System.lineSeparator());
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
