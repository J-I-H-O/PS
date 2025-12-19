package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Boj2565 {

    /**
     * 없애야 하는 최소 개수를 구하는 문제 == 배치할 수 있는 최대 개수를 구하는 문제
     * i번째 전기줄과 교차한다 == i번째 전기줄의 A 위치보다 높고 && B 위치보다 낮은 경우
     * 최장 증가 부분 수열(LIS) 문제
     * A에 대해서 정렬해두고, B에 대해 LIS 구하면 됨
     */
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[][] lines = new int[n][2];
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            lines[i][0] = Integer.parseInt(input[0]);
            lines[i][1] = Integer.parseInt(input[1]);
        }
        // [1, 8], [2, 2], [3, 9], [4, 1], [6, 4], [7, 6], [9, 7], [10, 10]
        Arrays.sort(lines, (line1, line2) -> line1[0] - line2[0]);

        // dp[i]: i번째 전깃줄을 선택했을 때의 LIS 길이
        // == i번째 전깃줄을 선택했을 때, 앞선 전깃줄들 중 설치할 수 있는 전깃줄들의 최대 개수 + 자기 자신 (1)
        int[] dp = new int[n];
        dp[0] = 1;  // 자기 자신 설치 가능

        // i번째 전깃줄을 설치하려면 i번째 전깃줄보다 A와 B 모두 낮은 전깃줄만 설치할 수 있음
        for (int i = 1; i < n; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (lines[j][1] > lines[i][1]) continue;
                max = Math.max(max, dp[j]);
            }
            dp[i] = max + 1;
        }

        // 제거해야 하는 전깃줄의 최소 개수 == (전체 전깃줄의 개수 - 겹치지 않고 설치할 수 있는 전깃줄의 최대 개수)
        int maxInstall = 0;
        for (int i = 0; i < n; i++) {
            maxInstall = Math.max(maxInstall, dp[i]);
        }
        System.out.println(n - maxInstall);
    }
}
