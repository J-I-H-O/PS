package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj16928 {

    /**
     * 100번 칸에 도착할 때 까지 BFS
     */
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[] board = new int[101];
        for (int i = 0; i < N + M; i++) {
            input = br.readLine().split(" ");
            board[Integer.parseInt(input[0])] = Integer.parseInt(input[1]);
        }

        boolean[] visited = new boolean[101];
        visited[1] = true;

        Queue<int[]> queue = new LinkedList<>();    // {현재 칸의 번호, 주사위를 굴린 횟수}
        queue.add(new int[]{1, 0});

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curBoard = cur[0];
            int curCnt = cur[1];

            if (curBoard == 100) {
                System.out.println(curCnt);
                break;
            }

            for (int i = 1; i <= 6; i++) {
                int nextBoard = curBoard + i;

                if (nextBoard > 100) continue;
                if (visited[nextBoard]) continue;

                // 다음 칸에 사다리 또는 뱀이 존재하지 않는 경우
                if (board[nextBoard] == 0) {
                    visited[nextBoard] = true;
                    queue.add(new int[]{nextBoard, curCnt + 1});
                    continue;
                }

                // 다음 칸에 사다리 또는 뱀이 존재하는 경우
                if (visited[board[nextBoard]]) continue;
                visited[nextBoard] = true;
                visited[board[nextBoard]] = true;
                queue.add(new int[]{board[nextBoard], curCnt + 1});
            }
        }
    }
}
