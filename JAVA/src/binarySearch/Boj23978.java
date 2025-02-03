package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj23978 {

    static int N;
    static long K;
    static int[] days;

    static long calculateX() {
        // 이분탐색을 사용해 x값 찾기. 현금화한 금액이 목표치보다 작으면 x 증가, 현금화한 금액이 목표치보다 크면 x 감소
        long start = 1;
        long end = (long) Math.sqrt(2 * K); // (x(x+1))/2 < K 이므로, x의 최대값을 어림잡아 계산하면 Math.sqrt(2 * K) 보다 작음
        while (start < end) {
            long x = (start + end) / 2;
            long sum = 0;
            for (int i = 0; i < N - 1; i++) {
                long daysDiff = days[i + 1] - days[i];
                if (daysDiff > x) {
                    daysDiff = x;
                }

                long sum1 = (x * (x + 1)) / 2;
                long sum2 = ((x - daysDiff) * (x - daysDiff + 1)) / 2;
                sum += sum1 - sum2;
            }
            sum += (x * (x + 1)) / 2;

            if (sum < K) {
                start = x + 1;
            } else if (sum > K) {
                end = x;
            } else {
                return x;
            }
        }
        return end;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Long.parseLong(input[1]);

        input = br.readLine().split(" ");
        days = new int[N];
        for (int i = 0; i < N; i++) {
            days[i] = Integer.parseInt(input[i]);
        }

        System.out.println(calculateX());
    }
}
