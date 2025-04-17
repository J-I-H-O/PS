package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj2563 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        boolean[][] isCovered = new boolean[101][101];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            int leftOffset = Integer.parseInt(input[0]);
            int downOffset = Integer.parseInt(input[1]);

            for (int j = leftOffset; j < leftOffset + 10; j++) {
                for (int k = downOffset; k < downOffset + 10; k++) {
                    isCovered[j][k] = true;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (isCovered[i][j]) {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}
