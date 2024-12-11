package bruteForce;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj17127 {

    public static int calcGroupMul(int[] blossoms, int startIdx, int endIdx) {
        int result = 1;
        for (int i = startIdx; i <= endIdx; i++) {
            result *= blossoms[i];
        }
        return result;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] blossomsInput = br.readLine().split(" ");

        int[] blossoms = new int[n];
        for (int i = 0; i < n; i++) {
            blossoms[i] = Integer.parseInt(blossomsInput[i]);
        }

        int ans = 0;
        for (int end1 = 0; end1 <= n - 4; end1++) {
            int group1 = calcGroupMul(blossoms, 0, end1);
            for (int end2 = end1 + 1; end2 <= n - 3; end2++) {
                int group2 = calcGroupMul(blossoms, end1 + 1, end2);
                for (int end3 = end2 + 1; end3 <= n - 2; end3++) {
                    int group3 = calcGroupMul(blossoms, end2 + 1, end3);
                    int group4 = calcGroupMul(blossoms, end3 + 1, n - 1);
                    ans = Math.max(ans, group1 + group2 + group3 + group4);
                }
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }
}
