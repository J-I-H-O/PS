package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Boj2504 {

    static Deque<String> deque = new ArrayDeque<>();
    static char[] arr;

    static int calc() {
        for (int i = 0; i < arr.length; i++) {
            char ch = arr[i];
            if (ch == '(' || ch == '[') {
                deque.add(String.valueOf(ch));
                continue;
            }

            if (deque.isEmpty()) {
                return 0;
            }

            if (ch == ')') {
                if (deque.peekLast().equals("(")) {
                    deque.removeLast();
                    deque.add("2");
                } else {
                    int temp = 0;
                    while (!deque.isEmpty() && !deque.peekLast().equals("(")) {
                        if (deque.peekLast().equals("[")) {
                            return 0;
                        }
                        temp += Integer.parseInt(deque.removeLast());
                    }
                    if (deque.isEmpty()) {
                        return 0;
                    }
                    deque.removeLast();
                    deque.add(String.valueOf(temp * 2));
                }
            } else if (ch == ']') {
                if (deque.peekLast().equals("[")) {
                    deque.removeLast();
                    deque.add("3");
                } else {
                    int temp = 0;
                    while (!deque.isEmpty() && !deque.peekLast().equals("[")) {
                        if (deque.peekLast().equals("(")) {
                            return 0;
                        }
                        temp += Integer.parseInt(deque.removeLast());
                    }
                    if (deque.isEmpty()) {
                        return 0;
                    }
                    deque.removeLast();
                    deque.add(String.valueOf(temp * 3));
                }
            }
        }

        // 스택에 남은 수를 모두 합
        int result = 0;
        while (!deque.isEmpty()) {
            String cur = deque.removeLast();
            if (cur.equals("(") || cur.equals("[")) {
                return 0;
            }
            result += Integer.parseInt(cur);
        }
        return result;
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = br.readLine().toCharArray();
        System.out.println(calc());
    }
}
