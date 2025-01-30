package binarySearch;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj27968 {

    static int N;
    static int M;
    static int[] kid;
    static long[] sum;

    static int binarySearch(long target) {
        // M번 안에 목표 사탕 개수를 채우지 못하는 경우
        if (target > sum[M - 1]) {
            return -1;
        }

        // 아이가 원하는 사탕의 개수보다 큰 최소값을 찾기 위해 이분탐색
        int start = 0;
        int end = M - 1;
        while (start <= end && sum[start] < target) {
            int mid = (start + end) / 2;
            if (target == sum[mid]) {
                return mid + 1;
            } else if (target < sum[mid]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start + 1;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        // A1 ~ Ai 까지의 합 저장
        kid = new int[M];
        sum = new long[M];
        input = br.readLine().split(" ");
        sum[0] = Integer.parseInt(input[0]);
        for (int i = 1; i < M; i++) {
            sum[i] = sum[i - 1] + Integer.parseInt(input[i]);
        }

        for (int i = 0; i < N; i++) {
            int ans = binarySearch(Long.parseLong(br.readLine()));
            if (ans == -1) {
                bw.write("Go away!" + "\n");
            } else {
                bw.write(ans + "\n");
            }
        }
        bw.flush();
    }
}
