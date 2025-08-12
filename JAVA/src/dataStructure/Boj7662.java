package dataStructure;

import java.io.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Boj7662 {

    /**
     * 최소 힙, 최대 힙 동시에 사용. "D 1"의 경우 최대 힙에서, "D -1"의 경우 최소 힙에서 요소 삭제 이때 각 큐의 정합성이 맞지 않으므로, 요소가 큐에 실제로 존재하는지 파악해야 함 (Map 사용) 힙에서 요소를
     * 삭제할 때에는 Map에 해당 요소가 실제로 존재할 때 까지 삭제
     */
    static void remove(Map<Integer, Integer> map, PriorityQueue<Integer> heap) {
        while (!map.isEmpty()) {
            int target = heap.poll();
            int cnt = map.getOrDefault(target, 0);

            // 삭제하려는 숫자가 map에 존재하지 않는 경우는 (이전 명령어에서 이미 제거된 경우) 건너뜀
            if (cnt == 0) continue;

            if (cnt == 1) map.remove(target);
            else map.put(target, cnt - 1);

            break;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int TC = 0; TC < T; TC++) {
            PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Integer> minHeap = new PriorityQueue<>();
            Map<Integer, Integer> map = new HashMap<>();    // {입력 데이터, 큐에 남은 데이터의 개수}

            int k = Integer.parseInt(br.readLine());
            for (int i = 0; i < k; i++) {
                String[] input = br.readLine().split(" ");
                String command = input[0];
                int num = Integer.parseInt(input[1]);

                if ("I".equals(command)) {
                    // 양쪽 힙에 모두 삽입. map에는 입력 데이터의 개수 저장
                    maxHeap.add(num);
                    minHeap.add(num);
                    map.put(num, map.getOrDefault(num, 0) + 1);
                } else {
                    if (num == 1) remove(map, maxHeap);
                    else remove(map, minHeap);
                }
            }

            if (map.isEmpty()) {
                bw.write("EMPTY\n");
            } else {
                int max = Integer.MIN_VALUE;
                int min = Integer.MAX_VALUE;
                for (int key : map.keySet()) {
                    max = Math.max(max, key);
                    min = Math.min(min, key);
                }
                bw.write(max + " " + min + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
