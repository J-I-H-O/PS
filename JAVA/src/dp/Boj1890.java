package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1890 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[N][N];
        long[][] routeCnt = new long[N][N];

        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        routeCnt[0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    continue;
                }
                if (i + board[i][j] < N) {
                    routeCnt[i + board[i][j]][j] += routeCnt[i][j];
                }
                if (j + board[i][j] < N) {
                    routeCnt[i][j + board[i][j]] += routeCnt[i][j];
                }
            }
        }
        System.out.println(routeCnt[N - 1][N - 1]);
    }
}
