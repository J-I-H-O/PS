package dfs_bfs;

import java.util.LinkedList;
import java.util.Queue;

public class Pro43163 {

    public int solution(String begin, String target, String[] words) {
        // 전처리. 각 word 사이의 변환 가능성 찾기
        int newLength = words.length + 1;
        String[] newWords = new String[newLength];
        for (int i = 1; i < newLength; i++) {
            newWords[i] = words[i - 1];
        }
        newWords[0] = begin;

        boolean[][] isConvertable = new boolean[newLength][newLength];
        for (int i = 0; i < newLength; i++) {
            for (int j = 0; j < newLength; j++) {
                char[] s1 = newWords[i].toCharArray();
                char[] s2 = newWords[j].toCharArray();
                int defCnt = 0;

                for (int k = 0; k < s1.length; k++) {
                    if (s1[k] != s2[k]) {
                        defCnt++;
                    }
                }

                if (defCnt == 1) {
                    isConvertable[i][j] = true;
                }
            }
        }

        // bfs로 변환 횟수 구하기
        Queue<int[]> queue = new LinkedList<>();    // {현재 단어 번호, 변환 횟수}
        queue.add(new int[]{0, 0});

        boolean[] visited = new boolean[newLength];
        visited[0] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int curStringNum = cur[0];
            int convertCnt = cur[1];

            if (newWords[curStringNum].equals(target)) {
                return convertCnt;
            }

            for (int i = 0; i < newLength; i++) {
                if (isConvertable[curStringNum][i] && !visited[i]) {
                    queue.add(new int[]{i, convertCnt + 1});
                    visited[i] = true;
                }
            }
        }

        return 0;
    }
}
