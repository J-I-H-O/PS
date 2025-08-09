package dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Boj9019 {

    static int A, B;
    static char[] commands = {'D', 'S', 'L', 'R'};

    static class Register {
        int num;
        String command;

        public Register(int num, String command) {
            this.num = num;
            this.command = command;
        }
    }

    static int applyCommand(int num, char command) {
        if (command == 'D') {
            return (2 * num) % 10000;
        } else if (command == 'S') {
            return num == 0 ? 9999 : num - 1;
        } else if (command == 'L') {
            return ((num % 1000) * 10) + num / 1000;
        } else {
            return ((num % 10) * 1000) + num / 10;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        toNextTc:
        for (int tc = 0; tc < T; tc++) {
            String[] input = br.readLine().split(" ");
            A = Integer.parseInt(input[0]);
            B = Integer.parseInt(input[1]);

            boolean[] visited = new boolean[10000];

            Queue<Register> queue = new LinkedList<>();
            queue.add(new Register(A, ""));
            visited[A] = true;
            while (!queue.isEmpty()) {
                Register cur = queue.poll();
                if (cur.num == B) {
                    System.out.println(cur.command);
                    continue toNextTc;
                }

                for (char command : commands) {
                    int newNum = applyCommand(cur.num, command);
                    String newCommand = cur.command + command;

                    if (visited[newNum]) continue;

                    queue.add(new Register(newNum, newCommand));
                    visited[newNum] = true;
                }
            }
        }
    }
}
