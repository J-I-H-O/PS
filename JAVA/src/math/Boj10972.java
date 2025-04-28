package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj10972 {

    public static void solution() throws IOException {
        /**
         * 수열의 뒤에서부터 시작, arr[i-1] 과 arr[i]의 내림차순이 깨지는 순간 찾기
         * [5, 4, 2, 3, 1] 에서 arr[i-1] = 2, arr[i] = 3일 때 내림차순이 깨짐
         *
         * i-1 < j를 만족하면서, arr[i-1] 보다 큰 값 arr[j]를 갖는 j 찾기
         * [5, 4, 2, 3, 1] 에서 i-1 = 2, arr[i-1] = 2. 이때 j = 3, arr[j] = 3
         *
         * swap(arr[i-1], arr[j])
         * [5, 4, 3, 2, 1]
         *
         * i-1 이후의 숫자들을 역순으로 정렬 (기존 i-1 이후의 숫자들은 내림차순 정렬되어 있었으므로, 내림차순을 오름차순으로 재정렬한 것과 같음)
         * [5, 4, 3, 1, 2]
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        // 순열을 역순으로 살펴보며 내림차순이 깨지는 순간 찾기
        int idx = N - 1;
        while (idx > 0) {
            if (arr[idx] > arr[idx - 1]) {
                break;
            }
            idx--;
        }

        // 모든 원소가 내림차순 정렬된 경우
        if (idx == 0) {
            System.out.println(-1);
            return;
        }

        int pivot = idx - 1;
        int targetIdx = pivot + 1;
        for (int cur = pivot + 1; cur < N; cur++) {
            if (arr[cur] > arr[pivot] && arr[cur] < arr[targetIdx]) {
                targetIdx = cur;
            }
        }

        swap(arr, pivot, targetIdx);
        int left = pivot + 1;
        int right = N - 1;
        while (left < right) {
            swap(arr, left, right);
            left++;
            right--;
        }

        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < N; i++) {
            sb.append(arr[i]).append(" ");
        }
        System.out.println(sb);
    }

    public static void swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
}
