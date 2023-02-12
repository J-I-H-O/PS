#include <iostream>
using namespace std;

int a, b, c, m;
int fatigure = 0;   // 피로도
int work = 0;       // 처리한 일

int main() {
    cin >> a >> b >> c >> m;
    for(int i = 1; i <= 24; i++) {
        // 일을 할 수 있는 경우
        if(fatigure + a <= m) {
            fatigure += a;
            work += b;
        } else {
            fatigure -= c;
            if(fatigure < 0) {
              fatigure = 0;
            }
        }
    }
    cout << work;
    
    return 0;
}