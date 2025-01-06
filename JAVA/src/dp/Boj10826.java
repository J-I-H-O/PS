package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Boj10826 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        BigInteger[] nums = new BigInteger[10001];

        nums[0] = BigInteger.valueOf(0);
        nums[1] = BigInteger.valueOf(1);
        for (int i = 2; i <= 10000; i++) {
            nums[i] = nums[i - 1].add(nums[i - 2]);
        }

        System.out.println(nums[n]);
    }
}
