package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2748 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] nums = new long[91];

        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= 90; i++) {
            nums[i] = nums[i - 1] + nums[i - 2];
        }

        System.out.println(nums[n]);
    }
}
