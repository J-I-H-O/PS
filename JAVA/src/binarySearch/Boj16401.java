package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj16401 {

    public static void solution() throws IOException {
        // idea : 막대과자 길이를 매개변수로 파라메트릭 서치
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        int max = 0;
        int[] cookies = new int[N];
        for (int i = 0; i < N; i++) {
            cookies[i] = Integer.parseInt(input[i]);
            max = Math.max(max, cookies[i]);
        }

        // uppder bound
        int st = 1;
        int en = max;
        while (st <= en) {
            int mid = (st + en) / 2;
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (cnt >= M) {
                    break;
                }
                cnt += cookies[i] / mid;
            }

            if (cnt < M) {
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        System.out.println(st - 1);
    }
}
