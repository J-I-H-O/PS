package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj3079 {

    public static void solution() throws IOException {
        // idea : 모든 사람이 심사를 받는데 걸리는 시간을 매개변수로 파라메트릭 서치
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int min = Integer.MAX_VALUE;
        int[] T = new int[N];
        for (int i = 0; i < N; i++) {
            T[i] = Integer.parseInt(br.readLine());
            min = Math.min(min, T[i]);
        }

        // lower bound
        long left = 1;
        long right = (long) M * min;   // 모든 사람이 가장 시간이 적게 걸리는 심사대에만 줄을 서는 경우
        while (left < right) {
            long mid = (left + right) / 2;
            long capacity = 0;
            for (int i = 0; i < N; i++) {
                if (capacity >= M) {
                    break;
                }
                capacity += mid / T[i];
            }

            // mid 만큼의 시간이 흘렀을 때, 심사를 통과한 인원이 M보다 작은 경우
            if (capacity < M) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        System.out.println(right);
    }
}
