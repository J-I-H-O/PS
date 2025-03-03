package twoPointer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1806 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int S = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(input[i]);
        }

        int ans = N + 1;
        int curSum = nums[0];
        int left = 0, right = 0;
        while (left <= right) {
            if (curSum >= S) {
                ans = Math.min(ans, right - left + 1);
                curSum -= nums[left];
                left++;
            } else {
                // 더이상 오른쪽으로 움직일 수 없어 무한루프 도는 것을 막기 위함
                if (right + 1 >= N) {
                    break;
                }
                curSum += nums[right + 1];
                right++;
            }
        }

        if (ans == N + 1) {
            System.out.println(0);
        } else {
            System.out.println(ans);
        }
    }
}
