package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1051 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        char[][] square = new char[N][M];
        for (int i = 0; i < N; i++) {
            square[i] = br.readLine().toCharArray();
        }

        int ans = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int maxVertical = Math.max(N - i, 0);
                int maxHorizon = Math.max(M - j, 0);
                int maxDiagonal = Math.min(maxVertical, maxHorizon);
                for (int k = 1; k < maxDiagonal; k++) {
                    if (square[i][j] == square[i + k][j]
                            && square[i][j] == square[i][j + k]
                            && square[i][j] == square[i + k][j + k]) {
                        ans = Math.max(ans, k + 1);
                    }
                }
            }
        }
        System.out.println(ans * ans);
    }
}
