#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1024;
int k, temp;
int tree[MAX];  // 각 인덱스는 노드 번호. 1~1024
vector<int> input;

// st: 범위의 시작 인덱스, en: 범위의 끝 인덱스, idx: tree 배열에서 현재 노드의 인덱스
void fillTree(int st, int en, int idx) {
    
    int mid = (st + en) / 2;
    tree[idx] = input[mid];
    
    // 리프 노드인 경우 종료, 아니라면 자식 노드를 찾아감
    if(st >= en) return;
    else {
        fillTree(st, mid-1, idx*2);        // 왼쪽 구간
        fillTree(mid+1, en, idx*2 + 1);    // 오른쪽 구간    
    }
}

int main() {
    input.push_back(0); // dummy data
    
    cin >> k;
    for(int i = 1; i <= pow(2, k) - 1; i++) {
        cin >> temp;
        input.push_back(temp);
    }
    
    fillTree(1, pow(2, k) - 1, 1);
    
    // 출력
    for(int i = 0; i < k; i++) {   // 트리의 높이만큼 반복
        int idx = pow(2, i);
        for(int j = 0; j < idx; j++) {    
            cout << tree[idx + j] << " ";
        }
        cout << "\n";
    }    
    
    return 0;
}