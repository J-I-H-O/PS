package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj14888 {

    static int N;
    static int[] operands;
    static int[] operators = new int[4];
    static int min = Integer.MAX_VALUE;
    static int max = Integer.MIN_VALUE;

    static void permutation(int curResult, int operandIdx) {
        // 마지막 피연산자까지 계산 완료된 경우
        if (operandIdx == N) {
            min = Math.min(min, curResult);
            max = Math.max(max, curResult);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (operators[i] > 0) {
                operators[i]--;

                if (i == 0) {
                    permutation(curResult + operands[operandIdx], operandIdx + 1);
                } else if (i == 1) {
                    permutation(curResult - operands[operandIdx], operandIdx + 1);
                } else if (i == 2) {
                    permutation(curResult * operands[operandIdx], operandIdx + 1);
                } else {
                    permutation(curResult / operands[operandIdx], operandIdx + 1);
                }

                operators[i]++;
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        operands = new int[N];

        String[] input = br.readLine().split(" ");
        for (int i = 0; i < input.length; i++) {
            operands[i] = Integer.parseInt(input[i]);
        }

        input = br.readLine().split(" ");
        for (int i = 0; i < 4; i++) {
            operators[i] += Integer.parseInt(input[i]);
        }

        permutation(operands[0], 1);
        System.out.println(max);
        System.out.println(min);
    }
}
