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
        int curSum = 0;
        int left = 0, right = 0;
        while (left <= right && right < N) {
            if (curSum >= S) {
                ans = Math.min(ans, right - left);
                curSum -= nums[left++];
            } else {
                curSum += nums[right++];
            }
        }
        System.out.println(ans == N + 1 ? 0 : ans);
    }
}
