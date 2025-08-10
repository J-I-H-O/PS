package dataStructure;

import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Boj11279 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < N; i++) {
            int input = Integer.parseInt(br.readLine());
            if (input == 0) {
                if (maxHeap.isEmpty()) bw.write(0 + System.lineSeparator());
                else bw.write(maxHeap.poll() + System.lineSeparator());
            } else {
                maxHeap.add(input);
            }
        }
        bw.flush();
        bw.close();
    }
}
