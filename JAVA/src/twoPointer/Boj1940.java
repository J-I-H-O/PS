package twoPointer;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Boj1940 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int[] nums = Arrays.stream(br.readLine().split(" "))
                .mapToInt(num -> Integer.parseInt(num))
                .toArray();

        Arrays.sort(nums);

        int ans = 0;
        int idx1 = 0;
        int idx2 = nums.length - 1;
        while (idx1 < idx2) {
            if (nums[idx1] + nums[idx2] == m) {
                ans++;
                idx1++;
                idx2--;
            } else if (nums[idx1] + nums[idx2] < m) {
                idx1++;
            } else {
                idx2--;
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }
}
