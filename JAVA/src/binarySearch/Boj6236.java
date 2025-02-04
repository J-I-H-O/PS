package binarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj6236 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int max = 0;
        int[] amount = new int[N];
        for (int i = 0; i < N; i++) {
            int curAmount = Integer.parseInt(br.readLine());
            amount[i] = curAmount;
            max = Math.max(max, curAmount);
        }

        // idea: 인출 금액을 변수로 파라메트릭 서치
        // lower bound
        int left = max; // 금액이 부족할 경우 남은 돈을 모두 통장에 넣고 다시 돈을 인출하기 때문에, 하루에 사용할 금액의 최대값보다 큰 금액을 인출할 수 있어야 함
        int right = 100000 * 10000 + 1; // 100000일 동안 매일 10000원씩 사용할 때, 1번의 인출만으로 생활하고 싶은 경우 포함
        while (left < right) {
            int mid = (left + right) / 2;   // 한 번에 인출할 수 있는 금액
            int leftAmount = mid;           // 사용하고 남은 금액
            int withdrawCnt = 1;            // 인출 횟수
            for (int i = 0; i < N; i++) {
                if (leftAmount - amount[i] < 0) {
                    leftAmount = mid;
                    withdrawCnt++;
                }
                leftAmount -= amount[i];
            }

            if (withdrawCnt <= M) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(right);
    }
}
