package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj9663_Improved {

    static int ans = 0;
    static int N;
    static int[] board; // (index : row, value: col)

    public static boolean canPlaced(int row, int col) {
        // 재귀 조건 상 같은 행에 퀸이 존재할 수 없으므로 검증하지 않아도 됨
        // 같은 열에 퀸이 존재하는지 여부 검증
        for (int i = 0; i < row; i++) {
            if (board[i] == col) {
                return false;
            }
        }
        // 대각선에 퀸이 존재하는지 여부 검증
        // 두 점의 x 좌표의 차와 y 좌표의 차가 같은 경우 대각선 상에 있는 것
        for (int curRow = 0; curRow < row; curRow++) {
            if (Math.abs(curRow - row) == Math.abs(board[curRow] - col)) {
                return false;
            }
        }
        return true;
    }

    public static void placeQueen(int row) {
        // 마지막 row 까지 채워진 경우
        if (row == N) {
            ans++;
            return;
        }

        for (int col = 0; col < N; col++) {
            if (canPlaced(row, col)) {
                board[row] = col;
                placeQueen(row + 1);
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        board = new int[N];

        placeQueen(0);

        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
