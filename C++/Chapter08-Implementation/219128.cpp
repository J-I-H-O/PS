#include <iostream>
#include <vector>
using namespace std;

vector<int> bulb;
int n, m, temp;
int a, b, c;

int main() {
  cin >> n >> m;
  bulb.push_back(0);  // dummy data
  for (int i = 0; i < n; i++) {
    cin >> temp;
    bulb.push_back(temp);
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    switch (a) {
      case 1:
        bulb[b] = c;
        break;
      case 2:
        for (int i = b; i <= c; i++) {
          bulb[i] = (bulb[i] + 1) % 2;
        }
        break;
      case 3:
        for (int i = b; i <= c; i++) {
          bulb[i] = 0;
        }
        break;
      case 4:
        for (int i = b; i <= c; i++) {
          bulb[i] = 1;
        }
        break;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << bulb[i] << " ";
  }

  return 0;
}