#include <bits/stdc++.h>
using namespace std;

// 나이가 같을 경우, 가입 순서대로 정렬하기 위해 priority 멤버변수 선언
class Member {
  public:
  int priority; // 몇 번째로 가입했는지
  int age;
  string name;
};

bool comp(Member* a, Member* b) {
  if(a->age == b->age) {
    return a->priority < b->priority;
  }
  return a->age < b->age;
}

// 아래 함수를 sort와 함께 사용할 경우, stability(같은 우선순위를 가지는 값들을 정렬할 때 순서가 변하지 않는 성질)을 보장하지 않음
// bool comp(pair<int, string> a, pair<int, string> b) {
//   return a.first < b.first;
// }

int n;
int inputNum;
string inputStr;
vector<Member*> members;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    Member* tempMember = new Member();
    cin >> inputNum;
    cin >> inputStr;

    tempMember->priority = i;
    tempMember->age = inputNum;
    tempMember->name = inputStr;

    members.push_back(tempMember);
  }

  sort(members.begin(), members.end(), comp);

  for(int i = 0; i < members.size(); i++) {
    cout << members[i]->age << " " << members[i]->name << "\n";
    delete members[i];
  }

  return 0;
}