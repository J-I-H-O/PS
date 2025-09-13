package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj12100 {

    static int N;
    static int ans;

    static void move(int[][] board, int moveCnt) {
        if (moveCnt == 5) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    ans = Math.max(ans, board[i][j]);
                }
            }
            return;
        }

        move(moveUp(board), moveCnt + 1);
        move(moveDown(board), moveCnt + 1);
        move(moveLeft(board), moveCnt + 1);
        move(moveRight(board), moveCnt + 1);
    }

    static int[][] moveUp(int[][] board) {
        boolean[][] isMerged = new boolean[N][N];
        int[][] newBoard = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                newBoard[i][j] = board[i][j];
            }
        }

        for (int col = 0; col < N; col++) {
            for (int row = 1; row < N; row++) {
                for (int curRow = row; curRow > 0; curRow--) {
                    int nextRow = curRow - 1;
                    int curNum = newBoard[curRow][col];
                    int nextNum = newBoard[nextRow][col];

                    if (nextNum == 0) {
                        newBoard[curRow][col] = 0;
                        newBoard[nextRow][col] = curNum;
                    } else if (curNum == nextNum && !isMerged[nextRow][col]) {
                        newBoard[curRow][col] = 0;
                        newBoard[nextRow][col] = curNum + nextNum;
                        isMerged[nextRow][col] = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return newBoard;
    }

    static int[][] moveDown(int[][] board) {
        boolean[][] isMerged = new boolean[N][N];
        int[][] newBoard = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                newBoard[i][j] = board[i][j];
            }
        }

        for (int col = 0; col < N; col++) {
            for (int row = N - 2; row >= 0; row--) {
                // 한 칸씩 밀어가며 이동
                for (int curRow = row; curRow < N - 1; curRow++) {
                    int nextRow = curRow + 1;
                    int curNum = newBoard[curRow][col];
                    int nextNum = newBoard[nextRow][col];

                    if (nextNum == 0) {
                        newBoard[curRow][col] = 0;
                        newBoard[nextRow][col] = curNum;
                    } else if (curNum == nextNum && !isMerged[nextRow][col]) {
                        newBoard[curRow][col] = 0;
                        newBoard[nextRow][col] = curNum + nextNum;
                        isMerged[nextRow][col] = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return newBoard;
    }

    static int[][] moveLeft(int[][] board) {
        boolean[][] isMerged = new boolean[N][N];
        int[][] newBoard = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                newBoard[i][j] = board[i][j];
            }
        }

        for (int row = 0; row < N; row++) {
            for (int col = 1; col < N; col++) {
                for (int curCol = col; curCol > 0; curCol--) {
                    int nextCol = curCol - 1;
                    int curNum = newBoard[row][curCol];
                    int nextNum = newBoard[row][nextCol];

                    if (nextNum == 0) {
                        newBoard[row][curCol] = 0;
                        newBoard[row][nextCol] = curNum;
                    } else if (curNum == nextNum && !isMerged[row][nextCol]) {
                        newBoard[row][curCol] = 0;
                        newBoard[row][nextCol] = curNum + nextNum;
                        isMerged[row][nextCol] = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return newBoard;
    }

    static int[][] moveRight(int[][] board) {
        boolean[][] isMerged = new boolean[N][N];
        int[][] newBoard = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                newBoard[i][j] = board[i][j];
            }
        }

        for (int row = 0; row < N; row++) {
            for (int col = N - 2; col >= 0; col--) {
                for (int curCol = col; curCol < N - 1; curCol++) {
                    int nextCol = curCol + 1;
                    int curNum = newBoard[row][curCol];
                    int nextNum = newBoard[row][nextCol];

                    if (nextNum == 0) {
                        newBoard[row][curCol] = 0;
                        newBoard[row][nextCol] = curNum;
                    } else if (curNum == nextNum && !isMerged[row][nextCol]) {
                        newBoard[row][curCol] = 0;
                        newBoard[row][nextCol] = curNum + nextNum;
                        isMerged[row][nextCol] = true;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        return newBoard;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[][] board = new int[N][N];

        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        move(board, 0);
        System.out.println(ans);
    }
}
