package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj23978_naive_timeout {

    static int N;
    static long K;
    static int[] days;

    static long calculateX() {
        // naive: x = 1 ~ k 까지 일일히 구해보기
        for (long x = 1; x <= K; x++) {
            long curPrice = 0;
            long sum = 0;
            long dayCnt = 0;
            int dayIdx = 0;

            while (curPrice != 0 || dayIdx < N) {
                if (dayIdx < N && dayCnt == days[dayIdx]) {
                    curPrice = x;
                    dayIdx++;
                }

                sum += curPrice;
                if (sum >= K) {
                    return x;
                }

                if (curPrice > 0) {
                    curPrice--;
                }
                dayCnt++;
            }
        }
        return -1;
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
