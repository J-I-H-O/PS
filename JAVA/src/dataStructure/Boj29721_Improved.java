package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Boj29721_Improved {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int[] dx = new int[]{2, 0, -2, 0};
        int[] dy = new int[]{0, 2, 0, -2};
        Set<String> visited = new HashSet<>();

        for (int i = 0; i < K; i++) {
            input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            visited.add(x + "," + y);

            for (int j = 0; j < 4; j++) {
                int nextX = x + dx[j];
                int nextY = y + dy[j];

                if (nextX < 1 || nextX > N || nextY < 1 || nextY > N) {
                    continue;
                }
                visited.add(nextX + "," + nextY);
            }
        }
        System.out.println(visited.size() - K);
    }
}
