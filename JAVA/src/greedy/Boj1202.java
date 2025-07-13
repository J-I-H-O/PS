package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Boj1202 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int[][] jewels = new int[N][2]; // {무게, 가격}
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            jewels[i][0] = Integer.parseInt(input[0]);
            jewels[i][1] = Integer.parseInt(input[1]);
        }

        int[] bags = new int[K];
        for (int i = 0; i < K; i++) {
            bags[i] = Integer.parseInt(br.readLine());
        }

        // 무게 순 오름차순 정렬
        Arrays.sort(jewels, (jewel1, jewel2) -> jewel1[0] - jewel2[0]);
        Arrays.sort(bags);

        // 우선 순위 큐에 현재 가방에 넣을 수 있는 보석들을 모두 넣고, 가장 가치가 높은 것 꺼내기
        // => 우선 순위 큐에서 꺼내기 때문에 중복으로 보석을 선택하지 않을 수 있음
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        // 시간 복잡도: O((N+K)logN)
        // 각 보석을 우선순위 큐에 삽입 : O(NlogN)
        // 가방의 개수만큼 보석을 우선순위 큐에서 제거 : O(KlogN)
        // => O(NlogN + KlogN) = O((N+K)logN)
        long ans = 0;
        int jewelIdx = 0;   // 다음으로 살펴볼 보석의 index
        for (int bag : bags) {
            // 보석을 무게 순으로 오름차순 정렬해두었으므로, 가방에 들어갈 수 있는 보석을 순차적으로 탐색 가능
            while (jewelIdx < N && jewels[jewelIdx][0] <= bag) {
                pq.add(jewels[jewelIdx][1]);
                jewelIdx++;
            }

            if (!pq.isEmpty()) {
                ans += pq.poll();
            }
        }
        System.out.println(ans);
    }
}
