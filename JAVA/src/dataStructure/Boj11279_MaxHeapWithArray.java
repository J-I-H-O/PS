package dataStructure;

import java.io.*;

public class Boj11279_MaxHeapWithArray {

    static class MaxHeap {
        int[] heap = new int[100001];
        int size = 0;

        public void add(int num) {
            int curIdx = ++size;
            int parentIdx = curIdx / 2;
            heap[curIdx] = num;
            while (parentIdx > 0 && heap[curIdx] > heap[parentIdx]) {
                swap(curIdx, parentIdx);
                curIdx = parentIdx;
                parentIdx /= 2;
            }
        }

        public int poll() {
            // empty
            if (size == 0) return 0;

            int result = heap[1];
            heap[1] = heap[size--];

            int targetIdx = 1;
            int left = targetIdx * 2;
            int right = targetIdx * 2 + 1;

            // 리프 노드가 아닐 때까지 반복
            while (left <= size) {
                int largerChild = left;
                if (right <= size && heap[left] < heap[right]) largerChild = right;
                if (heap[largerChild] < heap[targetIdx]) break;

                swap(targetIdx, largerChild);

                targetIdx = largerChild;
                left = targetIdx * 2;
                right = targetIdx * 2 + 1;
            }
            return result;
        }

        private void swap(int idx1, int idx2) {
            int temp = heap[idx1];
            heap[idx1] = heap[idx2];
            heap[idx2] = temp;
        }
    }

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        MaxHeap maxHeap = new MaxHeap();
        for (int i = 0; i < N; i++) {
            int input = Integer.parseInt(br.readLine());
            if (input == 0) {
                bw.write(maxHeap.poll() + System.lineSeparator());
            } else {
                maxHeap.add(input);
            }
        }
        bw.flush();
        bw.close();
    }
}
