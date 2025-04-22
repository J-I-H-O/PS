package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj3085 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        char[][] candies = new char[N][N];
        for (int i = 0; i < N; i++) {
            candies[i] = br.readLine().toCharArray();
        }

        int[] dx = new int[]{1, -1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};

        int ans = 0;
        for (int curX = 0; curX < N; curX++) {
            for (int curY = 0; curY < N; curY++) {
                for (int i = 0; i < 4; i++) {
                    int nextX = curX + dx[i];
                    int nextY = curY + dy[i];
                    if (0 > nextX || nextX >= N || 0 > nextY || nextY >= N) {
                        continue;
                    }
                    swap(candies, curX, curY, nextX, nextY);

                    // 각 행의 연속된 색 최대 길이 구하기
                    for (int x = 0; x < N; x++) {
                        char curColor = candies[x][0];
                        int sequenceCnt = 1;
                        for (int y = 0; y < N - 1; y++) {
                            if (candies[x][y + 1] != curColor) {
                                curColor = candies[x][y + 1];
                                sequenceCnt = 1;
                            } else {
                                sequenceCnt++;
                            }
                            ans = Math.max(ans, sequenceCnt);
                        }
                    }

                    // 각 열의 연속된 색 최대 길이 구하기
                    for (int y = 0; y < N; y++) {
                        char curColor = candies[0][y];
                        int sequenceCnt = 1;
                        for (int x = 0; x < N - 1; x++) {
                            if (candies[x + 1][y] != curColor) {
                                curColor = candies[x + 1][y];
                                sequenceCnt = 1;
                            } else {
                                sequenceCnt++;
                            }
                            ans = Math.max(ans, sequenceCnt);
                        }
                    }

                    swap(candies, nextX, nextY, curX, curY);
                }
            }
        }
        System.out.println(ans);
    }

    private static void swap(char[][] candies, int x1, int y1, int x2, int y2) {
        char temp = candies[x1][y1];
        candies[x1][y1] = candies[x2][y2];
        candies[x2][y2] = temp;
    }
}
