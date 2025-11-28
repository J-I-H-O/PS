package unionFind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10775 {

    static int[] parent;

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int G = Integer.parseInt(br.readLine());
        int P = Integer.parseInt(br.readLine());

        parent = new int[G + 1];
        for (int i = 1; i <= G; i++) {
            parent[i] = i;
        }

        /**
         * - 그리디: 현재 입력받은 gate와 가장 가까운 게이트에 도킹시켜야 함
         *          (gate가 이미 도킹된 상태라면 gate-1 번째에, gate-1 번째에도 도킹된 상태라면 gate-2... 번째에 도킹)
         *
         * - union-find: 각 gate는 자신이 도킹 불가능한 상태라면 차선책을 제시해야 함
         *
         * - parent[gate]: gate가 도킹 불가능한 상태일 때 도킹 가능한 게이트 번호.
         *   초기 상태에는 gate 자기 자신을 나타내다가, 도킹되었을 때 차선책으로 자신의 이전 게이트를 나타내도록 변경 (union(emptyGate, emptyGate - 1))
         *   만약 차선책들의 parent를 타고 타고 올라가다가 0을 만나는 경우는 더이상 도킹할 게이트가 없다는 의미
         */
        int ans = 0;
        for (int i = 0; i < P; i++) {
            int gate = Integer.parseInt(br.readLine());
            int emptyGate = findCurRootOf(gate);

            if (emptyGate == 0) break;

            union(emptyGate, emptyGate - 1);
            ans++;
        }
        System.out.println(ans);
    }

    public static int findCurRootOf(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findCurRootOf(parent[x]);
    }

    public static void union(int x, int y) {
        x = findCurRootOf(x);
        y = findCurRootOf(y);

        parent[x] = y;
    }
}
