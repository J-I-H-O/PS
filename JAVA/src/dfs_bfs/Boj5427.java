package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj5427 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < testCase; tc++) {
            String[] input = br.readLine().split(" ");
            int w = Integer.parseInt(input[0]);
            int h = Integer.parseInt(input[1]);

            Queue<int[]> humanQueue = new LinkedList<>();
            Queue<int[]> fireQueue = new LinkedList<>();

            char[][] map = new char[h][w];
            for (int i = 0; i < h; i++) {
                char[] curLine = br.readLine().toCharArray();
                for (int j = 0; j < w; j++) {
                    map[i][j] = curLine[j];
                    if (map[i][j] == '*') {
                        fireQueue.add(new int[]{i, j, 1});
                    }
                    if (map[i][j] == '@') {
                        humanQueue.add(new int[]{i, j, 1});
                    }
                }
            }

            int[] dr = {1, -1, 0, 0};
            int[] dc = {0, 0, 1, -1};

            // 이번 차례에 번져야 하는 불들을 표시하기 위함
            int firePhase = fireQueue.isEmpty() ? 0 : fireQueue.peek()[2];
            int humanPhase = 1;
            boolean isExitFound = false;

            // 더이상 이동할 수 없을 때 까지 반복
            out:
            while (!humanQueue.isEmpty()) {
                // 이번 차례에 번져야 하는 불들에 대해 번짐 처리
                while (!fireQueue.isEmpty() && fireQueue.peek()[2] == firePhase) {
                    int[] curFireInfo = fireQueue.poll();
                    for (int i = 0; i < 4; i++) {
                        int nextFireR = curFireInfo[0] + dr[i];
                        int nextFireC = curFireInfo[1] + dc[i];

                        if (nextFireR < 0 || nextFireR >= h || nextFireC < 0 || nextFireC >= w) continue;
                        if (map[nextFireR][nextFireC] == '#' || map[nextFireR][nextFireC] == '*') continue;

                        map[nextFireR][nextFireC] = '*';
                        fireQueue.add(new int[]{nextFireR, nextFireC, firePhase + 1});
                    }
                }
                firePhase++;

                // 이동 처리
                while (!humanQueue.isEmpty() && humanQueue.peek()[2] == humanPhase) {
                    int[] curHumanInfo = humanQueue.poll();
                    int curHumanR = curHumanInfo[0];
                    int curHumanC = curHumanInfo[1];
                    if (curHumanR == 0 || curHumanR == h - 1 || curHumanC == 0 || curHumanC == w - 1) {
                        isExitFound = true;
                        System.out.println(humanPhase);
                        break out;
                    }

                    for (int i = 0; i < 4; i++) {
                        int nextHumanR = curHumanR + dr[i];
                        int nextHumanC = curHumanC + dc[i];

                        if (nextHumanR < 0 || nextHumanR >= h || nextHumanC < 0 || nextHumanC >= w) continue;
                        if (map[nextHumanR][nextHumanC] != '.') continue;

                        map[nextHumanR][nextHumanC] = '@';
                        humanQueue.add(new int[]{nextHumanR, nextHumanC, humanPhase + 1});
                    }
                }
                humanPhase++;
            }
            if (!isExitFound) {
                System.out.println("IMPOSSIBLE");
            }
        }
    }
}
