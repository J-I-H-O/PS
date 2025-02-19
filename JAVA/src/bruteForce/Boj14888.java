package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj14888 {

    static int N;
    static int[] operands;
    static List<Character> operators = new ArrayList<>();
    static List<Character> selected = new ArrayList<>();
    static boolean[] visited;
    static int min = Integer.MAX_VALUE;
    static int max = Integer.MIN_VALUE;

    static int calc() {
        int result = operands[0];
        for (int i = 0; i < selected.size(); i++) {
            char operator = selected.get(i);
            if (operator == '+') {
                result += operands[i + 1];
            } else if (operator == '-') {
                result -= operands[i + 1];
            } else if (operator == '*') {
                result *= operands[i + 1];
            } else {
                result /= operands[i + 1];
            }
        }
        return result;
    }

    static void permutation() {
        if (selected.size() == N - 1) {
            int result = calc();
            min = Math.min(min, result);
            max = Math.max(max, result);
            return;
        }

        for (int i = 0; i < operators.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                selected.add(operators.get(i));
                permutation();
                selected.remove(selected.size() - 1);
                visited[i] = false;
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        operands = new int[N];
        visited = new boolean[N - 1];

        String[] input = br.readLine().split(" ");
        for (int i = 0; i < input.length; i++) {
            operands[i] = Integer.parseInt(input[i]);
        }

        input = br.readLine().split(" ");
        for (int i = 0; i < input.length; i++) {
            char targetOperator;
            if (i == 0) {
                targetOperator = '+';
            } else if (i == 1) {
                targetOperator = '-';
            } else if (i == 2) {
                targetOperator = '*';
            } else {
                targetOperator = '/';
            }

            for (int j = 0; j < Integer.parseInt(input[i]); j++) {
                operators.add(targetOperator);
            }
        }

        permutation();
        System.out.println(max);
        System.out.println(min);
    }
}
