package bruteForce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Boj1062 {

    static List<String> words = new ArrayList<>();
    static boolean[] learned = new boolean[26];
    static int N, K;
    static int ans = 0;

    static boolean isReadable(String word) {
        for (int i = 0; i < word.length(); i++) {
            if (!learned[word.charAt(i) - 'a']) {
                return false;
            }
        }
        return true;
    }

    static void combination(int curIdx, int learnCnt) {
        if (learnCnt == K) {
            int readableCnt = 0;
            for (String word : words) {
                if (isReadable(word)) {
                    readableCnt++;
                }
            }
            ans = Math.max(ans, readableCnt);
            return;
        }

        for (int i = curIdx; i < 26; i++) {
            if (!learned[i]) {
                learned[i] = true;
                combination(i + 1, learnCnt + 1);
                learned[i] = false;
            }
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);

        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            words.add(word.substring(4, word.length() - 4));    // "anta", "tica"를 제거한 단어
        }

        if (K < 5) {
            System.out.println(0);
            return;
        }

        // "anta", "tica" 는 반드시 배워야 함
        learned['a' - 'a'] = learned['n' - 'a'] = learned['t' - 'a'] = learned['i' - 'a'] = learned['c' - 'a'] = true;
        combination(0, 5);
        System.out.println(ans);
    }
}
