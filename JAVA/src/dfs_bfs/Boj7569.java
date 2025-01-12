package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj7569 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);
        int H = Integer.parseInt(input[2]);

        Queue<int[]> queue = new LinkedList<>();
        int[][][] tomatoes = new int[H][N][M];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                input = br.readLine().split(" ");
                for (int k = 0; k < M; k++) {
                    tomatoes[i][j][k] = Integer.parseInt(input[k]);
                    if (tomatoes[i][j][k] == 1) {
                        queue.add(new int[]{i, j, k});
                    }
                }
            }
        }

        int[] dh = {1, -1, 0, 0, 0, 0};
        int[] dn = {0, 0, 1, -1, 0, 0};
        int[] dm = {0, 0, 0, 0, 1, -1};
        while (!queue.isEmpty()) {
            int[] curPos = queue.remove();  // h, n, m
            int curH = curPos[0];
            int curN = curPos[1];
            int curM = curPos[2];
            for (int i = 0; i < 6; i++) {
                int nextH = curH + dh[i];
                int nextN = curN + dn[i];
                int nextM = curM + dm[i];
                if (0 <= nextH && nextH < H && 0 <= nextN && nextN < N && 0 <= nextM && nextM < M
                        && tomatoes[nextH][nextN][nextM] == 0) {
                    queue.add(new int[]{nextH, nextN, nextM});
                    tomatoes[nextH][nextN][nextM] = tomatoes[curH][curN][curM] + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (tomatoes[i][j][k] == 0) {
                        System.out.println(-1);
                        return;
                    }
                    ans = Math.max(ans, tomatoes[i][j][k]);
                }
            }
        }
        System.out.println(ans - 1);
    }
}
