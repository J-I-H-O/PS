package unionFind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1717 {

    static int n, m;
    static int[] parent;

    static void union(int a, int b) {
        int parentA = findParent(a);
        int parentB = findParent(b);

        if (parentA > parentB) {
            parent[parentA] = parentB;
        } else {
            parent[parentB] = parentA;
        }
    }

    static int findParent(int child) {
        if (parent[child] == child) {
            return child;
        }
        return parent[child] = findParent(parent[child]);
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        parent = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int command = Integer.parseInt(input[0]);
            int a = Integer.parseInt(input[1]);
            int b = Integer.parseInt(input[2]);

            if (command == 0) {
                union(a, b);
            } else {
                if (findParent(a) == findParent(b)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
