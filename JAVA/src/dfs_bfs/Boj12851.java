package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj12851 {

    // 칸에 방문할 때마다 해당 칸에 moveCnt 기록.
    // 만약 이동 시 현재 movecnt가 해당 칸에 기록된 moveCnt보다 높은 경우는 고려하지 않음
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int[] move = new int[100001];
        for (int i = 0; i < 100001; i++) {
            move[i] = Integer.MAX_VALUE;
        }

        int ans = Integer.MAX_VALUE;
        int ansCnt = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(N);
        move[N] = 0;
        while (!queue.isEmpty()) {
            int pos = queue.poll();

            if (pos == K) {
                ans = move[pos];
                ansCnt++;
                continue;
            }

            for (int i = 0; i < 3; i++) {
                int nextPos = pos;

                if (i == 0) nextPos -= 1;
                if (i == 1) nextPos += 1;
                if (i == 2) nextPos *= 2;

                if (0 > nextPos || nextPos >= 100001) continue;
                if (move[nextPos] < move[pos] + 1) continue;

                queue.add(nextPos);
                move[nextPos] = move[pos] + 1;
            }
        }
        System.out.println(ans);
        System.out.println(ansCnt);
    }
}
