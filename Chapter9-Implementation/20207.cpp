#include <iostream>
using namespace std;

int n, s, e;
int ans = 0;
int calendar[366];  // 각 날짜의 일정 수를 나타냄

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        for(int j = s; j <= e; j++) {
            calendar[j]++;
        }
    }
    
    // 코팅지의 가로 길이: 일정이 연속되는 일 수
    // 코팅지의 세로 길이: 일정이 연속될 때 일정의 최대 개수
    int width = 0;
    int height = 0;
    
    for(int i = 1; i <= 365; i++) {
        if(calendar[i] != 0) {
            width++;
        }
        
        if(height < calendar[i]) {
            height = calendar[i];
        }
        
        // 코팅지를 자르는 조건
        if(width != 0 && (calendar[i] == 0 || i == 365)) {
            ans += width * height;
            width = 0;
            height = 0;
        }
    }
    cout << ans;
    
    return 0;
}