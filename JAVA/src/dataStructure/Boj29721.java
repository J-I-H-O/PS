package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class Boj29721 {

    public static void solution() throws IOException {
        class Position {
            public int x;
            public int y;

            public Position(int x, int y) {
                this.x = x;
                this.y = y;
            }

            @Override
            public boolean equals(Object o) {
                Position position = (Position) o;
                return x == position.x && y == position.y;
            }

            @Override
            public int hashCode() {
                return Objects.hash(x, y);
            }
        }
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int[] dx = new int[]{2, 0, -2, 0};
        int[] dy = new int[]{0, 2, 0, -2};
        Set<Position> visited = new HashSet<>();

        for (int i = 0; i < K; i++) {
            input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]);
            int y = Integer.parseInt(input[1]);
            visited.add(new Position(x, y));

            for (int j = 0; j < 4; j++) {
                int nextX = x + dx[j];
                int nextY = y + dy[j];

                if (nextX < 1 || nextX > N || nextY < 1 || nextY > N) {
                    continue;
                }
                visited.add(new Position(nextX, nextY));
            }
        }
        System.out.println(visited.size() - K);
    }
}
