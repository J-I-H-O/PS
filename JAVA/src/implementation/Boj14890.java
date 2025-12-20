package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj14890 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int L = Integer.parseInt(input[1]);

        int[][] map = new int[N][N];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        int ans = 2 * N;

        // 가로 방향 길 찾기
        for (int row = 0; row < N; row++) {
            int prevHeight = map[row][0];
            for (int col = 0; col < N; col++) {
                // 이전 칸과 현재 칸의 높이가 같은 경우
                int streakLength = 0;
                while ((col + streakLength < N) && map[row][col + streakLength] == map[row][col]) {
                    streakLength++;
                }

                // 이전 칸 또는 다음 칸과 높이 차이가 1을 초과하는 경우, 경사로를 놓을 수 없음
                if (Math.abs(prevHeight - map[row][col]) > 1 || (col + streakLength < N && Math.abs(map[row][col + streakLength] - map[row][col]) > 1)) {
                    ans--;
                    break;
                }

                // 현재 구간 시작점의 이전 칸이 자신보다 높고, 현재 구간 끝점의 다음 칸이 자신보다 높은 경우
                if ((col - 1 >= 0 && prevHeight > map[row][col]) && (col + streakLength < N && map[row][col] < map[row][col + streakLength])) {
                    // 현재 구간의 양 끝에 경사로를 하나씩(총 2개) 배치 해야 함
                    if (streakLength < L * 2) {
                        ans--;
                        break;
                    }
                }

                // 현재 구간 시작점의 이전 칸만 자신보다 높은 경우
                if ((col - 1 >= 0 && prevHeight > map[row][col]) && (col + streakLength >= N || map[row][col] > map[row][col + streakLength])) {
                    if (streakLength < L) {
                        ans--;
                        break;
                    }
                }

                // 현재 구간 끝점의 다음 칸만 자신보다 높은 경우
                if ((col - 1 < 0 || prevHeight < map[row][col]) && (col + streakLength < N && map[row][col] < map[row][col + streakLength])) {
                    if (streakLength < L) {
                        ans--;
                        break;
                    }
                }
                prevHeight = map[row][col];
                col += streakLength - 1;
            }
        }

        // 세로 방향 길 찾기
        for (int col = 0; col < N; col++) {
            int prevHeight = map[0][col];
            for (int row = 0; row < N; row++) {
                // 이전 칸과 현재 칸의 높이가 같은 경우
                int streakLength = 0;
                while ((row + streakLength < N) && map[row + streakLength][col] == map[row][col]) {
                    streakLength++;
                }

                // 이전 칸 또는 다음 칸과 높이 차이가 1을 초과하는 경우, 경사로를 놓을 수 없음
                if (Math.abs(prevHeight - map[row][col]) > 1
                        || (row + streakLength < N && Math.abs(map[row + streakLength][col] - map[row][col]) > 1)) {
                    ans--;
                    break;
                }

                // 현재 구간 시작점의 이전 칸이 자신보다 높고, 현재 구간 끝점의 다음 칸이 자신보다 높은 경우
                if ((row - 1 >= 0 && prevHeight > map[row][col]) && (row + streakLength < N && map[row][col] < map[row + streakLength][col])) {
                    // 현재 구간의 양 끝에 경사로를 하나씩(총 2개) 배치 해야 함
                    if (streakLength < L * 2) {
                        ans--;
                        break;
                    }
                }

                // 현재 구간 시작점의 이전 칸만 자신보다 높은 경우
                if ((row - 1 >= 0 && prevHeight > map[row][col]) && (row + streakLength >= N || map[row][col] > map[row + streakLength][col])) {
                    if (streakLength < L) {
                        ans--;
                        break;
                    }
                }

                // 현재 구간 끝점의 다음 칸만 자신보다 높은 경우
                if (row + streakLength < N && map[row][col] < map[row + streakLength][col]) {
                    if (streakLength < L) {
                        ans--;
                        break;
                    }
                }
                prevHeight = map[row][col];
                row += streakLength - 1;
            }
        }
        System.out.println(ans);
    }
}
