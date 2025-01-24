package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Set;

public class Boj25178 {

    static Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(br.readLine());
        String str1 = br.readLine();
        String str2 = br.readLine();
        String vowelRemoved1 = "";
        String vowelRemoved2 = "";

        // 두 문자열이 같은 알파벳으로 이루어져 있는지 판별
        int[] cnt = new int[26];
        for (int i = 0; i < length; i++) {
            cnt[str1.charAt(i) - 'a']++;
            cnt[str2.charAt(i) - 'a']--;

            if (!vowels.contains(str1.charAt(i))) {
                vowelRemoved1 += str1.charAt(i);
            }
            if (!vowels.contains(str2.charAt(i))) {
                vowelRemoved2 += str2.charAt(i);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                System.out.println("NO");
                return;
            }
        }

        // 두 단어의 첫 글자와 마지막 글자가 동일한지 판별
        if (str1.charAt(0) != str2.charAt(0) || str1.charAt(str1.length() - 1) != str2.charAt(str2.length() - 1)) {
            System.out.println("NO");
            return;
        }

        // 두 단어에서 모음을 제거한 문자열이 동일한지 판별
        if (!vowelRemoved1.equals(vowelRemoved2)) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
    }
}
