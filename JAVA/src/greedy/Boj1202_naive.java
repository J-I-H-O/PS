package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Boj1202_naive {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        boolean[] isTaken = new boolean[N];
        int[][] jewels = new int[N][2]; // {무게, 가격}
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            jewels[i][0] = Integer.parseInt(input[0]);
            jewels[i][1] = Integer.parseInt(input[1]);
        }

        int[] bags = new int[K];
        for (int i = 0; i < K; i++) {
            bags[i] = Integer.parseInt(br.readLine());
        }

        // 무게 순 오름차순 정렬
        Arrays.sort(jewels, (jewel1, jewel2) -> jewel1[0] - jewel2[0]);
        Arrays.sort(bags);

        // O(NK)
        long ans = 0;
        for (int bag : bags) {
            int max = 0;
            int maxIdx = -1;
            for (int i = 0; i < N; i++) {
                if (bag < jewels[i][0]) break;
                // i번째 가방에 담을 수 있는 보석 중 가장 가치가 높은 것 찾기
                if (max < jewels[i][1] && !isTaken[i]) {
                    max = jewels[i][1];
                    maxIdx = i;
                }
            }

            if (maxIdx != -1) {
                isTaken[maxIdx] = true;
                ans += max;
            }
        }
        System.out.println(ans);
    }
}
