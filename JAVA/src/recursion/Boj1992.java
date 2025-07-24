package recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1992 {

    static char[][] board;
    static String ans = "";

    public static void compress(int r1, int c1, int r2, int c2) {
        boolean isCompressible = true;
        char dot = board[r1][c1];

        out:
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (board[i][j] != dot) {
                    isCompressible = false;
                    break out;
                }
            }
        }

        // 현재 탐색 중인 구간 ((r1,c1) ~ (r2~c2)) 을 하나의 숫자로 압축할 수 있는 경우 압축
        if (isCompressible) {
            ans += dot;
            return;
        }

        // 현재 탐색 중인 구간 ((r1,c1) ~ (r2~c2)) 을 하나의 숫자로 압축할 수 없는 경우 네 개의 구간으로 나누어 재귀
        ans += "(";
        compress(r1, c1, (r1 + r2) / 2, (c1 + c2) / 2);
        compress(r1, ((c1 + c2) / 2) + 1, (r1 + r2) / 2, c2);
        compress(((r1 + r2) / 2) + 1, c1, r2, (c1 + c2) / 2);
        compress(((r1 + r2) / 2) + 1, ((c1 + c2) / 2) + 1, r2, c2);
        ans += ")";
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        board = new char[N][N];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }

        compress(0, 0, N - 1, N - 1);
        System.out.println(ans);
    }
}
