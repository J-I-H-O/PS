package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1300 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Integer.parseInt(br.readLine());
        long k = Integer.parseInt(br.readLine());

        long st = 1;
        long en = N * N;
        while (st < en) {
            long mid = (st + en) / 2;
            long lessThanOrEqualToMidCnt = 0;
            for (int i = 1; i <= N; i++) {
                lessThanOrEqualToMidCnt += Math.min(N, mid / i);
            }

            if (lessThanOrEqualToMidCnt < k) {
                st = mid + 1;
            } else {
                en = mid;
            }
        }
        System.out.println(en);
    }
}
