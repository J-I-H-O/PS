package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Boj1715 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Long> heap = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            long deck = Long.parseLong(br.readLine());
            heap.add(deck);
        }

        long ans = 0;
        while (heap.size() > 1) {
            long deck1 = heap.remove();
            long deck2 = heap.remove();

            ans += deck1 + deck2;
            heap.add(deck1 + deck2);
        }
        System.out.println(ans);
    }
}
