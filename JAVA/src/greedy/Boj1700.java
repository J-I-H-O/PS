package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class Boj1700 {

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        input = br.readLine().split(" ");
        int[] plugs = new int[K];
        Map<Integer, Queue> priorities = new HashMap<>();
        for (int i = 0; i < K; i++) {
            plugs[i] = Integer.parseInt(input[i]);
            if (priorities.get(plugs[i]) == null) {
                priorities.put(plugs[i], new LinkedList());
            }
            priorities.get(plugs[i]).add(i);
        }

        Set<Integer> pluggedIn = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < K; i++) {
            if (pluggedIn.contains(plugs[i])) {
                Queue<Integer> queue = priorities.get(plugs[i]);
                if (!queue.isEmpty()) {
                    queue.remove();
                }
            } else if (pluggedIn.size() < N) {
                pluggedIn.add(plugs[i]);
                priorities.get(plugs[i]).remove();
            } else {
                // 콘센트에 꽂힌 플러그 중 우선순위가 가장 먼 플러그 뽑기
                int targetPlug = 0;
                int maxPriority = 0;
                for (int plug : pluggedIn) {
                    Queue<Integer> queue = priorities.get(plug);
                    // 현재 보고있는 플러그가 다음에 사용될 일이 없는 경우 바로 뽑아도 됨
                    if (queue.isEmpty()) {
                        targetPlug = plug;
                        break;
                    }
                    int curPriority = queue.peek();
                    if (maxPriority < curPriority) {
                        targetPlug = plug;
                        maxPriority = curPriority;
                    }
                }
                pluggedIn.remove(targetPlug);
                pluggedIn.add(plugs[i]);
                priorities.get(plugs[i]).remove();
                ans++;
            }
        }
        System.out.println(ans);
    }
}
