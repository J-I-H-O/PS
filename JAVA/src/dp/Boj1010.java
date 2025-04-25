package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1010 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        long[][] comb = new long[31][31];
        for (int n = 0; n <= 30; n++) {
            comb[n][0] = comb[n][n] = 1;    // nC0 = nCn = 1
        }
        for (int n = 1; n <= 30; n++) {
            for (int r = 1; r < n; r++) {
                comb[n][r] = comb[n - 1][r - 1] + comb[n - 1][r];   // nCr = n-1Cr-1 + n-1Cr (파스칼 삼각형)
            }
        }

        for (int TC = 0; TC < T; TC++) {
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);
            System.out.println(comb[M][N]);
        }
    }
}
