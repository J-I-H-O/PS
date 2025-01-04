package bruteForce;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj9663_Naive {

    static int ans = 0;
    static int n = 0;
    static boolean[][] map = new boolean[15][15];   // true: 해당 좌표에 퀸이 존재함
    static int placedCount = 0;

    // 현재 좌표에 퀸을 놓을 수 있는지 여부 확인
    static boolean canPlaced(int row, int col) {
        if (0 > row || row >= n || 0 > col || col >= n) {
            return false;
        }
        // 상하좌우
        for (int i = 0; i < n; i++) {
            if (map[i][col]) {
                return false;
            }
            if (map[row][i]) {
                return false;
            }
        }
        // 왼쪽 위
        for (int curRow = row, curCol = col; curRow >= 0 && curCol >= 0; curRow--, curCol--) {
            if (map[curRow][curCol]) {
                return false;
            }
        }
        // 오른쪽 위
        for (int curRow = row, curCol = col; curRow >= 0 && curCol < n; curRow--, curCol++) {
            if (map[curRow][curCol]) {
                return false;
            }
        }
        // 왼쪽 아래
        for (int curRow = row, curCol = col; curRow < n && curCol >= 0; curRow++, curCol--) {
            if (map[curRow][curCol]) {
                return false;
            }
        }
        // 오른쪽 아래
        for (int curRow = row, curCol = col; curRow < n && curCol < n; curRow++, curCol++) {
            if (map[curRow][curCol]) {
                return false;
            }
        }
        return true;
    }

    static void putQueen(int row, int col) {
        if (placedCount == n) {
            ans++;
            return;
        }

        for (int curCol = 0; curCol < n; curCol++) {
            if (canPlaced(row, curCol)) {
                map[row][curCol] = true;
                placedCount++;
                putQueen(row + 1, 0);
                placedCount--;
                map[row][curCol] = false;
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        putQueen(0, 0);

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }
}
