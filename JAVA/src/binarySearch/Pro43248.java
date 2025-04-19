package binarySearch;

public class Pro43248 {

    public long solution(int n, int[] times) {
        int minTime = times[0];
        for (int time : times) {
            if (time < minTime) {
                minTime = time;
            }
        }

        // 모든 사람의 심사가 완료되는 최소 시간을 기준으로 파라메트릭 서치
        long start = 0;
        long end = (long) minTime * n;  // 둘 다 int 형이므로, 계산 과정에서 overflow 발생. 형변환 필수
        while (start < end) {
            // 현재 심사에 소요된 시간
            long mid = (start + end) / 2;

            // 현재 시간 기준, 모든 심사대를 통과한 사람의 최대 수
            long sum = 0;
            for (int time : times) {
                sum += mid / time;
            }

            if (sum >= n) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
}
