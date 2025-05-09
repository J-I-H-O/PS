package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj17404_naive {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[][] color = new int[N][3];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 3; j++) {
                color[i][j] = Integer.parseInt(input[j]);
            }
        }

        // dp[i][j][k]: i번째 집을 j번 색으로 칠했을 때 비용의 합의 최솟값 (단, 0번째 집을 k번 색으로 칠함)
        int[][][] dp = new int[N][3][3];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = 1000001;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            dp[0][i][i] = color[0][i];
        }
        dp[1][0][0] = 1000001;  // 0 번집을 0, 1번 집을 0으로 칠하는 경우는 없음
        dp[1][1][0] = dp[0][0][0] + color[1][1];// 0번 집을 0, 1번 집을 1로 칠하는 경우
        dp[1][2][0] = dp[0][0][0] + color[1][2];// 0번 집을 0, 1번 집을 2로 칠하는 경우

        dp[1][0][1] = dp[0][1][1] + color[1][0];// 0번 집을 1, 1번 집을 0으로 칠하는 경우
        dp[1][1][1] = 1000001;  // 0번 집을 1, 1번 집을 1로 칠하는 경우는 없음
        dp[1][2][1] = dp[0][1][1] + color[1][2];// 0번 집을 1, 1번 집을 2로 칠하는 경우

        dp[1][0][2] = dp[0][2][2] + color[1][0];// 0번 집을 2, 1번 집을 0으로 칠하는 경우
        dp[1][1][2] = dp[0][2][2] + color[1][1];// 0번 집을 2, 1번 집을 0으로 칠하는 경우
        dp[1][2][2] = 1000001;  // 0번 집을 2, 1번 집을 2로 칠하는 경우는 없음

        for (int i = 2; i < N; i++) {
            for (int k = 0; k < 3; k++) {
                dp[i][0][k] = Math.min(dp[i - 1][1][k], dp[i - 1][2][k]) + color[i][0];
                dp[i][1][k] = Math.min(dp[i - 1][0][k], dp[i - 1][2][k]) + color[i][1];
                dp[i][2][k] = Math.min(dp[i - 1][0][k], dp[i - 1][1][k]) + color[i][2];
            }
        }
        dp[N - 1][0][0] = 1000001;
        dp[N - 1][1][1] = 1000001;
        dp[N - 1][2][2] = 1000001;

        int ans = 1000001;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ans = Math.min(ans, dp[N - 1][i][j]);
            }
        }
        System.out.println(ans);
    }
}
