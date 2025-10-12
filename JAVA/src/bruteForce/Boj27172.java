package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Boj27172 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        int[] nums = new int[N];
        Map<Integer, Integer> points = new HashMap<>();

        int maxNum = 0;
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(input[i]);
            points.put(nums[i], 0);
            maxNum = Math.max(maxNum, nums[i]);
        }
        int[] originNums = Arrays.copyOf(nums, N);

        for (int num : nums) {
            for (int mul = 2; num * mul <= maxNum; mul++) {
                if (points.get(num * mul) == null) continue;

                points.put(num, points.get(num) + 1);
                points.put(num * mul, points.get(num * mul) - 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int num : originNums) {
            sb.append(points.get(num)).append(" ");
        }
        System.out.println(sb);
    }
}
